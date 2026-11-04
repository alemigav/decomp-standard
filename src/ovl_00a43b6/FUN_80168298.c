/* FUN_80168298
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80168298  body 0x80168298..0x801683cf  size 312 B
 * body sha256 9c91504b90ded3ff1497202be2bd466c46f6ff641a695344209863338dcf84ff
 * provider record sha256 0d6059d4270344493f91b72d5d8152dc32349e4282a9f7539d7370eff10cbdfe
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80168298(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033144(param_1,&DAT_800e1130);
    *(uint *)(param_1 + 0x1e8) = (4 - (uVar1 & 0xff)) * 0x1000000 + 0x300;
    *(undefined1 *)(param_1 + 6) = 1;
    func_0x80077d18(9,param_1);
    *(char *)(param_1 + 0x2c4) = *(char *)(param_1 + 0x2c4) + '\x01';
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x200;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
  }
  func_0x80032b5c(param_1,0);
  if (*(char *)(param_1 + 0x1e9) == '\x0f') {
    if (*(char *)(param_1 + 5) == '\x0e') {
      FUN_8016780c(param_1);
    }
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xfdff;
  }
  return;
}
