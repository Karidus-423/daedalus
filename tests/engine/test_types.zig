const std = @import("std");
const testing = std.testing;
const mem = std.mem;
const io = @cImport(@cInclude("io/io.h"));
const dt = @cImport(@cInclude("types/types.h"));

fn Zig_StringGetSub(str: []const u8, start: u32, end: u32) []const u8 {
    return str[start..end];
}

test "Test String_GetSub" {
    const input : dt.String = .{ .chars = "examplestringedge",.len = 18 };
    const in_ptr: [*c]const dt.String = @ptrCast(&input);

    const actual: [*c] dt.String  = dt.String_GetSub(in_ptr, 7, 14);
    const expect = Zig_StringGetSub("examplestringedge", 7, 13);

    try testing.expect(mem.eql(u8, expect, mem.span(actual.*.chars)));
}

// fn Zig_ParseString(string: []u8, char: u8) !void {
// }

// test "Test String_Parse" {
//     const input: dt.String = .{
//         .chars = "filename.extension1.extension2",
//         .len = 31,
//     };
//
//     const expected = dt.String_Parse(input, '.');
//     const actual = Zig_ParseString(input,'.');
//
//     testing.expect(mem.eql(u8, expected, actual));
// }
