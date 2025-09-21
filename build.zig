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

    // const mod_tests = b.addTest(.{
    //     .root_module = mod,
    // });

    // const run_mod_tests = b.addRunArtifact(mod_tests);

    const exe_tests = b.addTest(.{
        .root_module = exe.root_module,
    });

    const run_exe_tests = b.addRunArtifact(exe_tests);

    const test_step = b.step("test", "Run tests");
    // test_step.dependOn(&run_mod_tests.step);
    test_step.dependOn(&run_exe_tests.step);
}
