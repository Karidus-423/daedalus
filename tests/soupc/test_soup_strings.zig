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
    const s= "ACABAD";
    const sub= "CAB";

    const to_slice = soup.RemoveSubString(s, sub);
    const wrapped_res = mem.span(to_slice);

    try expect(mem.eql(u8, wrapped_res, "ACD"));
}

test "Test ParseString" {
    const s = "filename.extension.extension2";
}
