/* FUN_80167064
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80167064  body 0x80167064..0x8016710b  size 168 B
 * body sha256 7397f91c66dbb2dc71a457943d407fa8578f3c4a94b421d489b9a1c468372e59
 * provider record sha256 303654fb02142de89113c9365ee4a1ddf2e9e34f9a6e6ffe1ddc9204a7a05a1e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167064(undefined4 param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  
  if (*(char *)(param_2 + 0x12) == '\0') {
    uVar1 = func_0x80033604();
    iVar3 = (uVar1 & 7) - 3;
    uVar1 = func_0x80033604();
    if ((uVar1 & 1) != 0) {
      FUN_801671cc(iVar3 * 0x10000 >> 0x10);
    }
    if ((uVar1 & 2) != 0) {
      FUN_8016721c(iVar3 * 0x10000 >> 0x10);
    }
    bVar2 = func_0x80033604();
    *(byte *)(param_2 + 0x12) = *(char *)(param_2 + 0x11) * (bVar2 & 7);
  }
  else {
    *(char *)(param_2 + 0x12) = *(char *)(param_2 + 0x12) + -1;
  }
  return;
}
