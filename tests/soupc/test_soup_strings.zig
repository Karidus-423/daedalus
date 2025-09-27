const std = @import("std");
const expect = std.testing.expect;
const soup = @cImport({
    @cDefine("SOUPC_STRINGS_IMPLEMENTED", {});
    @cInclude("../../src/soupc/soup-strings.h");
});

test "Test RemoveSubstring"{
    try expect();
}
