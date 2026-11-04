/* FUN_801655c0
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x801655c0  body 0x801655c0..0x8016581b  size 604 B
 * body sha256 cb17189210b8462baa824d7a1205b3d6ad63540d575351c9b1fb2e36652c4dd7
 * provider record sha256 f9080104422561d9fb7c26b75deba191efb783e1b3425d463900e76595378709
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801655c0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  ushort uVar3;
  short sVar4;
  char cVar5;
  undefined1 uVar6;
  byte bVar7;
  uint uVar2;
  int iVar8;
  
  bVar7 = *(byte *)((int)param_1 + 6);
  if (bVar7 != 1) {
    if (1 < bVar7) {
      if (bVar7 != 2) {
        return;
      }
      bVar1 = true;
      if (0x5a < *(short *)(param_1 + 0x7d)) {
        bVar7 = *(char *)((int)param_1 + 0x2b6) + 1;
        bVar1 = (bVar7 & 1) == 0;
        *(byte *)((int)param_1 + 0x2b6) = bVar7;
      }
      if (bVar1) {
        if (((*(char *)((int)param_1 + 0x1e9) == '\0') &&
            (uVar2 = func_0x80033604(param_1), (uVar2 & 1) != 0)) &&
           (*(short *)(param_1 + 0x7d) < 0x5a)) {
          func_0x80077d18(3,param_1);
        }
        func_0x80089d54(param_1,param_2,param_3,0x200);
        *(char *)((int)param_1 + 0x2b5) = *(char *)((int)param_1 + 0x2b5) + -1;
      }
      if (*(char *)((int)param_1 + 0x2b5) != '\0') {
        return;
      }
      uVar2 = func_0x80033604();
      iVar8 = (uint)*(ushort *)(param_1 + 0x7d) + (uVar2 & 0xf) + 10;
      *(short *)(param_1 + 0x7d) = (short)iVar8;
      if (iVar8 * 0x10000 >> 0x10 < 0x97) {
        *(undefined1 *)((int)param_1 + 6) = 1;
        *(undefined1 *)((int)param_1 + 0x2b5) = *(undefined1 *)((int)param_1 + 0x1f5);
        return;
      }
      *(undefined1 *)((int)param_1 + 6) = 3;
      return;
    }
    if (bVar7 != 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 0x26f) = 0x80;
    param_1[0x7a] = 0xb000700;
    *param_1 = *param_1 | 2;
    uVar3 = func_0x80033604();
    sVar4 = (uVar3 & 0x1f) + 0x19;
    *(char *)((int)param_1 + 0x2b5) = (char)sVar4;
    *(short *)(param_1 + 0x7d) = sVar4;
    func_0x800341dc(param_1[0x82],_DAT_800c76b0);
    *(undefined2 *)(param_1[0x82] + 4) = 400;
    *(undefined2 *)(param_1[0x82] + 6) = 400;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0x3c;
    *(undefined1 *)((int)param_1 + 6) = 1;
  }
  cVar5 = *(char *)((int)param_1 + 0x2b5) + -1;
  *(char *)((int)param_1 + 0x2b5) = cVar5;
  if (cVar5 == -1) {
    if (*(short *)(param_1 + 0x7d) < 0x5b) {
      uVar2 = func_0x80033604();
      uVar6 = 0xc;
      if ((uVar2 & 1) == 0) {
        *(undefined1 *)((int)param_1 + 0x1e9) = 0xb;
        uVar6 = 7;
      }
      else {
        *(undefined1 *)((int)param_1 + 0x1e9) = 0;
      }
    }
    else {
      *(undefined1 *)((int)param_1 + 0x1e9) = 0xb;
      uVar6 = 6;
    }
    *(undefined1 *)((int)param_1 + 0x2b5) = uVar6;
    *(undefined1 *)((int)param_1 + 6) = 2;
  }
  if (*(short *)((int)param_1 + 0x1f6) != 0) {
    *(short *)((int)param_1 + 0x1f6) = *(short *)((int)param_1 + 0x1f6) + -1;
    *(short *)(param_1[0x82] + 4) = *(short *)(param_1[0x82] + 4) + 10;
    *(short *)(param_1[0x82] + 6) = *(short *)(param_1[0x82] + 6) + 10;
  }
  return;
}
