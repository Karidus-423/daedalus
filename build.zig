const std = @import("std");

pub fn build(b: *std.Build) void {
    const architecture = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const engine = b.addExecutable(.{
        .name = "daedalus",
        .target = architecture,
        .optimize = optimize,
    });

    engine.linkLibC();
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

    const tests_mod = b.createModule(.{
        .root_source_file = b.path("tests/test_root.zig"),
        .target = architecture,
        .optimize = optimize,
    });
    
    const unit_tests = b.addTest(.{
        .root_module = tests_mod,
    });

    const run_unit_tests =  b.addRunArtifact(unit_tests);
    const tests_step = b.step("test", "Run unit tests");
    tests_step.dependOn(&run_unit_tests.step);
}
