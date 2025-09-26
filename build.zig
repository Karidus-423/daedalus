const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    // const mod = b.addModule("daedalus", .{
    //     .root_source_file = null,
    //     .link_libc = true,
    //     .target = target,
    // });

    const exe = b.addExecutable(.{
        .name = "daedalus",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            // .imports = &.{
            //     .{ .name = "daedalus", .module = mod },
            // },
        }),
    });

    exe.root_module.addCSourceFiles(.{
        .root = b.path("src"),
        .files = &.{
            "main.c",
            "draw.c",
            "update.c",
            "strings.c",
        },
        .language = .c,
    });

    exe.linkSystemLibrary("SDL3");
    exe.linkLibC();

    b.installArtifact(exe);

    const run_step = b.step("run", "Run the app");
    const run_cmd = b.addRunArtifact(exe);
    run_step.dependOn(&run_cmd.step);

    run_cmd.step.dependOn(b.getInstallStep());

    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const unit_tests = b.addExecutable(.{
        .name = "daedalus_tests",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            // .imports = &.{
            //     .{ .name = "daedalus", .module = mod },
            // },
        }),
    });

    unit_tests.root_module.addCSourceFiles(.{
        .root = b.path("src"),
        .files = &.{
            "tests/main_test.c",
            "strings.c",
            "tests/test_strings.c",
        },
        .language = .c,
    });

    unit_tests.linkSystemLibrary("SDL3");
    unit_tests.linkLibC();

    const unit_tests_step = b.step("test", "Run unit tests");
    const unit_tests_cmd = b.addRunArtifact(unit_tests);
    unit_tests_step.dependOn(&unit_tests_cmd.step);

}
