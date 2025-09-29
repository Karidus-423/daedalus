const std = @import("std");

pub fn build(b: *std.Build) void {
    const architecture = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const engine = b.addExecutable(.{
        .name = "daedalus",
        .root_module = b.createModule(.{
            .target = architecture,
            .optimize = optimize,
            .link_libc = true,
        }),
    });

    engine.linkSystemLibrary("SDL3");

    engine.addCSourceFiles(.{
        .files = &.{
            "src/main.c",
            "src/draw.c",
            "src/update.c",
            "src/models.c",
        },
    });

    b.installArtifact(engine);

    const run_engine_cmd = b.addRunArtifact(engine);
    run_engine_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_engine_cmd.addArgs(args);
    }

    const run_engine_step = b.step("run", "Run Daedalus");
    run_engine_step.dependOn(&run_engine_cmd.step);

    const tests = [_][]const u8{
        "tests/soupc/test_soup_strings.zig",
    };
    const tests_step = b.step("test", "Run unit tests");

    for (tests) |file| {
        const tests_mod = b.createModule(.{
            .root_source_file = b.path(file),
            .target = architecture,
            .optimize = optimize,
            .link_libc = true,
        });
        tests_mod.addIncludePath(b.path("soupc"));

        const unit_tests = b.addTest(.{
            .root_module = tests_mod,
        });
        unit_tests.linkSystemLibrary("SDL3");

        const run_unit_tests =  b.addRunArtifact(unit_tests);
        tests_step.dependOn(&run_unit_tests.step);
    }

}
