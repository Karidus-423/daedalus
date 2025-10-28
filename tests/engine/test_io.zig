const std = @import("std");
const testing = std.testing;
const mem = std.mem;
const engine = @cImport({
    @cInclude("io/io.h");
    @cInclude("types/types.h");
});

fn ZigReadFile(filename: []const u8) ![]u8 {
    const file = try std.fs.cwd().openFile(filename, .{});
    defer file.close();

    const file_size = try file.getEndPos();

    const allocator = std.heap.page_allocator;
    const buffer: []u8 = try allocator.alloc(u8, file_size);
    _ = try file.read(buffer);

    return buffer;
}

test "Test File_Read" {
    const filename: engine.String = .{ .chars = "assets/meshes/Teapot.obj", .len = 24 };
    const filename_ptr: [*c]const engine.String = @ptrCast(&filename);
    const zig_filename: []const u8 = mem.span(filename.chars);
    // const c_filename: dt.String = .{
    //     .chars = filename,
    //     .len = 25,
    // };

    const expect_contents = engine.File_Read(filename_ptr);
    const actual_contents = try ZigReadFile(zig_filename);
    defer std.heap.page_allocator.free(actual_contents);
    defer engine.SDL_free(expect_contents);

    try testing.expect(mem.eql(u8, mem.span(expect_contents.*.chars), actual_contents));
}
