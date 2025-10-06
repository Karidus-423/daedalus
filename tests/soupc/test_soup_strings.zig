const std = @import("std");
const mem = std.mem;
const debug = std.debug;
const expect = std.testing.expect;

const soup = @cImport({
    @cDefine("SOUPC_STRINGS_IMPLEMENTED", {});
    @cInclude("soup-strings.h");
});

// char* RemoveSubString(const char* string,const char* sub);
test "Test RemoveSubstring" {
    const s: []u8 = "ACABAD";
    const sub: []u8 = "CAB";

    const to_slice = soup.RemoveSubString(s, sub);
    const wrapped_res = mem.span(to_slice);

    try expect(mem.eql(u8, wrapped_res, "ACD"));
}

test "Test RemoveSubstring 2" {
    const s: []u8 = "ACABDCAB";
    const sub: []u8 = "CAB";

    const to_slice = soup.RemoveSubString(s, sub);
    const wrapped_res = mem.span(to_slice);

    try expect(mem.eql(u8, wrapped_res, "AD"));
}

test "Test ParseString" {
    const str: []u8 = "filename.extension.extension2";
    const expected_result: [][]u8 = &.{ "filename", "extension", "extension2" };

    const actual_res = soup.ParseString(str, ".");

    try expect(mem.eql([][]u8, actual_res, expected_result));
}

test "Test ParseString 2"{
    const str: []u8 = "filename[.]extension.extension2";
    const expected_result: [][]u8 = &.{ "filename", "extension", "extension2" };

    const actual_res = soup.ParseString(str, &.{"[.]","."});

    try expect(mem.eql([][]u8, actual_res, expected_result));
}

test "Test StringLength"{
    const str: []u8 = "The Length of this string is 32.";
    const expected_result: u8 = 32;

    try expect(soup.StringLength(str) == expected_result);
}

test "Test AppendString"{
    const str1: []u8 = "The original string.";
    const str2: []u8 = "The string to be appended/added.";

    const expected_result: []u8 = "The original string.The string to be appended/added.";

    const actual_result: []u8 = soup.AppendString(str1,str2);

    try expect(mem.eql([]u8, expected_result, actual_result));
}
