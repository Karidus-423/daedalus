const testing = std.testing;
const debug = std.debug;
const std = @import("std");
const mem = std.mem;
const io = @cImport(@cInclude("io/io.h"));
const dt = @cImport(@cInclude("types/types.h"));

//---TESTING STRING GET SUB-----------------------------------------------------------------------//
fn Zig_StringGetSub(str: []const u8, start: u32, end: u32) []const u8 {
    return str[start..end];
}

test "Test String_GetSub" {
    const input: dt.String = .{ .chars = "examplestringedge", .len = 18 };
    const in_ptr: [*c]const dt.String = @ptrCast(&input);

    const actual: [*c]dt.String = dt.String_GetSub(in_ptr, 7, 13);
    const expect = Zig_StringGetSub("examplestringedge", 7, 13);

    try testing.expect(mem.eql(u8, expect, mem.span(actual.*.chars)));
}
//------------------------------------------------------------------------------------------------//

//---TESTING STRING PARSE-------------------------------------------------------------------------//
test "Test String_Parse 1" {
    const input: dt.String = .{ .chars = "filename.extension1.extension2", .len = 31 };
    const in_ptr: [*c]const dt.String = @ptrCast(&input);

    var actual: [*c]dt.List = dt.String_Parse(in_ptr, '.');

    var node_num: i8 = 0;

    //TODO: Find the expression to cast a void* as String*. Read translated.zig and translate.c to
    //understand how to type cast the void*.
    while (actual.*.next != null) {
        actual = actual.*.next;
        const node_data_type: [*c]const dt.String =  @ptrCast(@alignCast(actual.*.data));
        const actual_data: []const u8 = mem.span(node_data_type.*.chars);

        try switch (node_num) {
            0 => testing.expect(mem.eql(u8, "extension2", actual_data)),
            1 => testing.expect(mem.eql(u8, "extension1", actual_data)),
            2 => testing.expect(mem.eql(u8, "filename", actual_data)),
            else => testing.expect(false),
        };
        node_num += 1;
    }
}

test "Test String_Parse 2" {
    const input: dt.String = .{ .chars = "filename.obj", .len = 13 };
    const in_ptr: [*c]const dt.String = @ptrCast(&input);

    var actual: [*c]dt.List = dt.String_Parse(in_ptr, '.');

    var node_num: i8 = 0;

    //TODO: Find the expression to cast a void* as String*. Read translated.zig and translate.c to
    //understand how to type cast the void*.
    while (actual.*.next != null) {
        actual = actual.*.next;
        const node_data_type: [*c]const dt.String =  @ptrCast(@alignCast(actual.*.data));
        const actual_data: []const u8 = mem.span(node_data_type.*.chars);

        try switch (node_num) {
            0 => testing.expect(mem.eql(u8, "obj", actual_data)),
            1 => testing.expect(mem.eql(u8, "filename", actual_data)),
            else => testing.expect(false),
        };
        node_num += 1;
    }
}

test "Test String_Parse 3" {
    const input: dt.String = .{ .chars = "assets/meshes/Teapot.obj", .len = 13 };
    const in_ptr: [*c]const dt.String = @ptrCast(&input);

    var actual: [*c]dt.List = dt.String_Parse(in_ptr, '.');

    debug.assert(actual != null);

    var node_num: i8 = 0;

    //TODO: Find the expression to cast a void* as String*. Read translated.zig and translate.c to
    //understand how to type cast the void*.
    while (actual.*.next != null) {
        actual = actual.*.next;
        const node_data_type: [*c]const dt.String =  @ptrCast(@alignCast(actual.*.data));
        const actual_data: []const u8 = mem.span(node_data_type.*.chars);

        try switch (node_num) {
            0 => testing.expect(mem.eql(u8, "obj", actual_data)),
            1 => testing.expect(mem.eql(u8, "assets/meshes/Teapot", actual_data)),
            else => testing.expect(false),
        };
        node_num += 1;
    }
}
//------------------------------------------------------------------------------------------------//
