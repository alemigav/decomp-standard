/* FUN_80165850
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165850  body 0x80165850..0x80165aa7  size 600 B
 * body sha256 77058b3a7b22e4d8444e701fd8cc97ab4fd8af0d1a766b60cb993149ecc7bde9
 * provider record sha256 69ccb6006c0506fac083a01079311c03341f47756e6d8643040ba182cbc6eda8
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165850(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  byte bVar4;
  undefined1 uVar5;
  char cVar7;
  int iVar6;
  uint uVar8;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    *(undefined1 *)((int)param_1 + 0x26f) = 0x80;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *param_1 = *param_1 | 2;
    uVar2 = func_0x80033604();
    sVar3 = (uVar2 & 0x1f) + 0x19;
    *(char *)((int)param_1 + 0x2b5) = (char)sVar3;
    *(short *)(param_1 + 0x7d) = sVar3;
    *(undefined1 *)(param_1[0x82] + 0xe) = 0;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0x3c;
    *(undefined1 *)((int)param_1 + 6) = 1;
  case 1:
    cVar7 = *(char *)((int)param_1 + 0x2b5) + -1;
    *(char *)((int)param_1 + 0x2b5) = cVar7;
    if (cVar7 != -1) {
      return;
    }
    param_1[0x7a] = 0x4000700;
    if (*(short *)(param_1 + 0x7d) < 0x79) {
      bVar4 = func_0x80033604();
      cVar7 = (bVar4 & 7) * '\x05' + '\x05';
    }
    else {
      bVar4 = func_0x80033604();
      cVar7 = (bVar4 & 1) * '\x05' + '\n';
    }
    *(char *)((int)param_1 + 0x2b5) = cVar7;
    uVar5 = 2;
    break;
  case 2:
    bVar1 = true;
    if (100 < *(short *)(param_1 + 0x7d)) {
      bVar4 = *(char *)((int)param_1 + 0x2b6) + 1;
      bVar1 = (bVar4 & 1) == 0;
      *(byte *)((int)param_1 + 0x2b6) = bVar4;
    }
    if (bVar1) {
      func_0x80089d54(param_1,param_2,param_3,0x200);
      if (*(short *)(param_1 + 0x7d) < 100) {
        *(char *)((int)param_1 + 0x1e9) = *(char *)((int)param_1 + 0x1e9) + '\x01';
      }
      *(char *)((int)param_1 + 0x2b5) = *(char *)((int)param_1 + 0x2b5) + -1;
    }
    if (*(char *)((int)param_1 + 0x2b5) != '\0') {
      return;
    }
    uVar8 = func_0x80033604();
    iVar6 = (uint)*(ushort *)(param_1 + 0x7d) + (uVar8 & 0xf) + 10;
    *(short *)(param_1 + 0x7d) = (short)iVar6;
    if (iVar6 * 0x10000 >> 0x10 < 0x97) {
      *(undefined1 *)((int)param_1 + 6) = 1;
      *(undefined1 *)((int)param_1 + 0x2b5) = *(undefined1 *)((int)param_1 + 0x1f5);
      return;
    }
    uVar5 = 3;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    break;
  case 3:
    uVar8 = (int)*(short *)((int)param_1 + 0x25e) - 0xfa;
    param_1[0xb] = param_1[0xb] + (int)*(short *)((int)param_1 + 0x1e2);
    *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x14;
    if ((int)param_1[0xb] <= (int)uVar8) {
      return;
    }
    FUN_80166294(param_1,0x15e);
    func_0x80077d18(5,param_1);
    param_1[0x7a] = 0xb000700;
    *(undefined1 *)((int)param_1 + 0x2b5) = 0xb;
    uVar5 = 4;
    *(undefined2 *)(param_1 + 0x1a) = 0;
    *(undefined2 *)(param_1 + 0x19) = 0;
    param_1[0xb] = uVar8;
    break;
  case 4:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    cVar7 = *(char *)((int)param_1 + 0x2b5) + -1;
    *(char *)((int)param_1 + 0x2b5) = cVar7;
    uVar5 = 5;
    if (cVar7 != -1) {
      return;
    }
    break;
  default:
    goto switchD_80165884_caseD_5;
  }
  *(undefined1 *)((int)param_1 + 6) = uVar5;
switchD_80165884_caseD_5:
  return;
}
