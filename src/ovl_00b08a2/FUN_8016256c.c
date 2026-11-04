/* FUN_8016256c
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x8016256c  body 0x8016256c..0x801625d3  size 104 B
 * body sha256 186db39e7359a9276d4c57f09afc8265b55f5b58923862c47c4f30df2ecb35ab
 * provider record sha256 93e93b4e93262ccd67431ca7633643adb2dfc3b7c8bd5eec305a07fc02216fae
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016256c(int param_1)

{
  ushort uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x3f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    uVar1 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar1 & 0x3f) + 0x3c;
    **(uint **)(param_1 + 0x234) = **(uint **)(param_1 + 0x234) & 0xfffffffe;
  }
  return;
}
