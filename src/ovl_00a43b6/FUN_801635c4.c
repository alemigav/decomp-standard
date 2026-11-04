/* FUN_801635c4
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801635c4  body 0x801635c4..0x80163757  size 404 B
 * body sha256 661597e9f11f5e3a1c0b23fa7b87537b07b0f796eb8f14c49660e7c1b2183285
 * provider record sha256 b708683e0822139a0a9a617acc0163ca9a0be0dc18b49b8e16753eb794faee57
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801635c4(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 3) {
        return;
      }
      func_0x800334c8(param_1,param_2,param_3,0);
      func_0x80089d54(param_1,param_2,param_3,0x100);
      func_0x80032b5c(param_1,0);
      if (*(char *)(param_1 + 0x1e9) == '\x12') {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
        *(undefined1 *)(param_1 + 0x2b6) = 0xf;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x17000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0x3c;
  }
  if (*(char *)(param_1 + 0x1ea) != '\0') {
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar2 != 0) {
    if (*(uint *)(param_1 + 0x28c) < 0xd48) {
      uVar3 = func_0x80033604();
      if ((uVar3 & 3) == 0) {
        *(undefined4 *)(param_1 + 0x1e8) = 0x6000f00;
        *(undefined1 *)(param_1 + 6) = 3;
        return;
      }
      *(undefined4 *)(param_1 + 4) = 0x1020000;
      return;
    }
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2b6) = 0xf;
  }
  func_0x80032b5c(param_1,0);
  return;
}
