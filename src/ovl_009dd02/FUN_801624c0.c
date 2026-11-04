/* FUN_801624c0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801624c0  body 0x801624c0..0x80162677  size 440 B
 * body sha256 534903aede2d6b32afd0fc3d9586a3c25a9ac937f9e43425f3b9ed7415bf5e01
 * provider record sha256 d7fa0adb45da56d65371f544d8a19bd8d098f9eb1949f878aadb0651c2c1e462
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801624c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  undefined1 *puVar4;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar4 = &DAT_800e1130;
  }
  else {
    puVar4 = _DAT_800e13ec;
  }
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if ((bVar1 == 2) &&
         (sVar2 = *(short *)(param_1 + 500), *(short *)(param_1 + 500) = sVar2 + -1, sVar2 == 1)) {
        *(undefined1 *)(param_1 + 5) = 1;
        *(undefined2 *)(param_1 + 6) = 0;
        *(undefined1 *)(param_1 + 0x2c9) = 0;
      }
      goto LAB_80162650;
    }
    if (bVar1 != 0) goto LAB_80162650;
    if (*(short *)(param_1 + 0x1aa) == 0x6002) {
      if (*(short *)(param_1 + 0x270) == 0) {
        return;
      }
      *(undefined2 *)(param_1 + 0x1aa) = 2;
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x2c1) = 1;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
    *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x2cd) * 0xd000000 + 0x3f00;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
    _DAT_800e1128 = _DAT_800e1128 & 0xffbf;
    *(undefined1 *)(param_1 + 0x2b6) = 1;
  }
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    uVar3 = *(uint *)(param_1 + 0x28c);
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
  }
  if ((uVar3 < 10000) && (-1 < *(short *)(puVar4 + 0x1f2))) {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined2 *)(param_1 + 500) = 0x1e;
    *(undefined1 *)(param_1 + 0x2c1) = 3;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  }
LAB_80162650:
  func_0x80089d54(param_1,param_2,param_3,0x40);
  FUN_80166a04(param_1);
  FUN_80162678(param_1);
  return;
}
