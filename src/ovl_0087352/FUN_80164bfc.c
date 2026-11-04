/* FUN_80164bfc
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80164bfc  body 0x80164bfc..0x80164ec7  size 716 B
 * body sha256 31568908e8ea8588690b36ad3ee62277bde270714d88f55b94905f9e9b96be64
 * provider record sha256 184529037f51fd7712b24ced185a7106d4ebdb733da52666e3b5a00d6a3b0442
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164bfc(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  char cVar4;
  undefined4 uVar5;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    func_0x80035b84(param_1);
    func_0x80077d18(3,param_1);
    FUN_80166294(param_1,100);
    *(undefined2 *)((int)param_1 + 0x1f2) = 0xffff;
    FUN_80166100(param_1);
    uVar3 = func_0x80033604();
    FUN_801661d8(param_1,(uVar3 & 3) + 3);
    param_1[0x7a] = 0x9000700;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) >> 1;
    *(short *)(param_1 + 0x79) = *(short *)(param_1 + 0x79) >> 1;
  case 1:
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar1 != 0) {
      *(undefined1 *)((int)param_1 + 6) = 2;
    }
switchD_80164c3c_caseD_2:
    param_1[0xb] = param_1[0xb] + (int)*(short *)((int)param_1 + 0x1e2);
    param_1[10] = param_1[10] + (int)*(short *)(param_1 + 0x78);
    *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x14;
    param_1[0xc] = param_1[0xc] + (int)*(short *)(param_1 + 0x79);
    uVar3 = (int)*(short *)((int)param_1 + 0x25e) - 0xfa;
    if ((int)uVar3 < (int)param_1[0xb]) {
      *(undefined1 *)((int)param_1 + 0x2b5) = 8;
      param_1[0xb] = uVar3;
      *(undefined2 *)(param_1 + 0x1a) = 0;
      *(undefined1 *)((int)param_1 + 6) = 3;
    }
    if ((param_1[0x6b] & 1) != 0) {
      if ((*param_1 & 0x4000) == 0) {
        uVar2 = func_0x80033604();
        *(ushort *)(param_1 + 0x1a) = (uVar2 & 1) * 0x800 + 0x400;
        uVar2 = func_0x80033604();
        *(ushort *)(param_1 + 0x19) = (uVar2 & 0xff) << 4;
        *(undefined2 *)((int)param_1 + 0x66) = 0;
      }
      else {
        uVar2 = func_0x80033604();
        *(ushort *)(param_1 + 0x19) = (uVar2 & 1) * 0x800 + 0x400;
        uVar2 = func_0x80033604();
        *(ushort *)((int)param_1 + 0x66) = (uVar2 & 0xff) << 4;
        *(undefined2 *)(param_1 + 0x1a) = 0;
      }
      param_1[0x7a] = 0x4000000;
      *(undefined1 *)((int)param_1 + 0x1e9) = 3;
      func_0x80089d54(param_1,param_2,param_3,0x200);
      uVar5 = 2;
LAB_80164ea8:
      FUN_80165c58(param_1,7,uVar5);
    }
    break;
  case 2:
    goto switchD_80164c3c_caseD_2;
  case 3:
    param_1[10] = param_1[10] + (int)*(short *)(param_1 + 0x78);
    param_1[0xc] = param_1[0xc] + (int)*(short *)(param_1 + 0x79);
    *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) >> 1;
    cVar4 = *(char *)((int)param_1 + 0x2b5) + -1;
    *(char *)((int)param_1 + 0x2b5) = cVar4;
    *(short *)(param_1 + 0x79) = *(short *)(param_1 + 0x79) >> 1;
    if (cVar4 == -1) {
      param_1[0x7a] = 0xb000700;
      *(undefined1 *)((int)param_1 + 0x2b5) = 0xb;
      *(undefined1 *)((int)param_1 + 6) = 4;
    }
    break;
  case 4:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    cVar4 = *(char *)((int)param_1 + 0x2b5) + -1;
    *(char *)((int)param_1 + 0x2b5) = cVar4;
    if (cVar4 != -1) {
      return;
    }
    uVar5 = 0;
    goto LAB_80164ea8;
  }
  return;
}
