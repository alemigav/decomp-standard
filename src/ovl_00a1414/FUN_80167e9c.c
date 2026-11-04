/* FUN_80167e9c
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80167e9c  body 0x80167e9c..0x80167fc7  size 300 B
 * body sha256 29698d294b20cbccf49e3e1971ad3e53a47c5afd1ac24eedf8da2da07a9c1a83
 * provider record sha256 1f2d459d7fc748dc430c7969e15bb4528bd58f9e4fc9065f092cd87b524cacdd
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80167e9c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 5) * 0x1000000 + 0x300;
    _DAT_800e110c = _DAT_800e110c | 0x40;
    *(undefined1 *)(param_1 + 0x25c) = 1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    uVar2 = 0x4010000;
    if (*(char *)(param_1 + 5) == '\0') {
      uVar2 = 0x4000000;
    }
    func_0x80077adc(uVar2 | 1,param_1 + 0x28);
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(undefined1 *)(param_1 + 0x25c) = 0;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
    _DAT_800e110c = _DAT_800e110c & 0xffffffbf;
  }
  func_0x80032b5c(param_1,0);
  return;
}
