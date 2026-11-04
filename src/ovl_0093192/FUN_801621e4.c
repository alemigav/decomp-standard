/* FUN_801621e4
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x801621e4  body 0x801621e4..0x80162307  size 292 B
 * body sha256 e1eecf7bd40e52c986adc03eccc395eb77c5fba0298c9ed81f9d67ea31aefc24
 * provider record sha256 2684de081d5e543e717a670e340025ec70a1bf78aa6592ae11993e51e8dd8f5b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801621e4(int param_1)

{
  byte bVar1;
  ushort uVar5;
  uint uVar2;
  undefined4 uVar3;
  short sVar6;
  int iVar4;
  undefined1 uVar7;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    uVar5 = func_0x80033604();
    bVar1 = *(byte *)(param_1 + 0x2bd);
    *(undefined1 *)(param_1 + 0x2bd) = 0;
    *(ushort *)(param_1 + 500) = (uVar5 & 0xff) + 0x1e & (ushort)bVar1 * 0x1e + 0x3f;
    uVar2 = func_0x80033604();
    uVar7 = 0x40;
    if ((0x1111 >> (uVar2 & 0xf) & 1U) != 0) {
      uVar7 = 0xc0;
    }
    *(undefined1 *)(param_1 + 0x2bf) = uVar7;
    if ((_DAT_800e110c & 0x10000000) != 0) {
      if (*(uint *)(param_1 + 0x28c) < (*(uint *)(param_1 + 0x290) & 0x3fffffff)) {
        uVar3 = 0x800e1130;
      }
      else {
        uVar3 = _DAT_800e13ec;
      }
      *(undefined4 *)(param_1 + 0x2b4) = uVar3;
    }
  }
  else if (*(char *)(param_1 + 7) != '\x01') goto LAB_801622e0;
  sVar6 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar6;
  if (sVar6 == -1) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
LAB_801622e0:
  iVar4 = FUN_80162c90(param_1);
  if (iVar4 == 0) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  return;
}
