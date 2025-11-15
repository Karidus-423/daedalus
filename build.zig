const std = @import("std");

pub fn build(b: *std.Build) void {
    const exe = b.addExecutable(.{
        .name = "daedalus",
        .root_module = b.createModule(.{
            .target = b.graph.host,
        }),
    });

    const daedalus_files : []const []const u8 = &.{
        "app-init.c",
    };

    exe.addCSourceFiles(.{
        .root = b.path("src"),
        .files = daedalus_files,
        .language = .c,
    });

    exe.linkSystemLibrary("SDL3");
    exe.linkLibC();

    b.installArtifact(exe);

    const run_daedalus = b.addRunArtifact(exe);
    const run_daedalus_step = b.step("run", "Run Daedalus.");
    run_daedalus_step.dependOn(&run_daedalus.step);
}
