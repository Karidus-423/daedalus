const std = @import("std");
const testing = std.testing;
const mem = std.mem;
const io = @cImport(@cInclude("io/io.h"));
const dt = @cImport(@cInclude("types/types.h"));


fn Zig_StringGetSub(str: []u8, start: u32, end:u32) []u8{
    return &str[start..end];
}

test "Test String_GetSub" {
    const input: dt.String = .{
        .chars = "examplestring",
        .len = 14,
    };

    const expect = Zig_StringGetSub(input.chars, 7, 14);
    const actual = dt.String_GetSub(input, 7, 14);

    testing.expect(mem.eql(u8, expect, actual.chars));
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
