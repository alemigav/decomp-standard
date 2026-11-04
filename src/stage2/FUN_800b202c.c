/* FUN_800b202c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b202c  body 0x800b202c..0x800b2097  size 108 B
 * body sha256 fee2570b22f4090a969e4df84c1c6e0fe09c55e441a6f8b9ab714b628a3ad168
 * provider record sha256 677b325101b87b73be00e3e6d81cf466d4478f8103017db5c6d0d4ef78d8c944
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b202c(undefined1 param_1,undefined2 param_2,undefined1 param_3)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a7b64(param_1,param_2,param_3,0,0);
    FUN_800a56c0();
  }
  return;
}
