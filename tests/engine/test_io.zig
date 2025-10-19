const std = @import("std");
const testing = std.testing;
const mem = std.mem;
const io = @cImport(@cInclude("io/io.h"));
const dt = @cImport(@cInclude("types/types.h"));

fn ZigReadFile(filename: []const u8) ![]u8 {
    const file  = try std.fs.cwd().openFile(filename, .{});
    defer file.close();

    const file_size = try file.getEndPos();

    const allocator = std.heap.page_allocator;
    const buffer: []u8 = try allocator.alloc(u8,file_size);
    _ = try file.read(buffer);

    return buffer;
}

test "Test File_Read" {
    const filename: [*:0]const u8 = "assets/meshes/Teapot.obj";
    const zig_filename: []const u8 = mem.span(filename);
    // const c_filename: dt.String = .{
    //     .chars = filename,
    //     .len = 25,
    // };

    const expect_contents = io.File_Read(filename);
    const actual_contents = try ZigReadFile(zig_filename);
    defer std.heap.page_allocator.free(actual_contents);
    defer io.SDL_free(expect_contents);

    try testing.expect(mem.eql(u8, mem.span(expect_contents.*.chars), actual_contents));
}
