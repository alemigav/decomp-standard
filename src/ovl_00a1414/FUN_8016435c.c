/* FUN_8016435c
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x8016435c  body 0x8016435c..0x80164727  size 972 B
 * body sha256 620d64b231be9d3c12a7860984b6892a8cd30fda9c5e0b1f07eeaa730490dd59
 * provider record sha256 e6994234f558448ab52ea71273070a7f6c0827c0bda3d0c66f81f68b6924176a
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016435c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  int iVar7;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0x7a] = 0xe001f00;
    *(undefined1 *)((int)param_1 + 6) = 1;
    if (_DAT_800e8caa == 3) {
      uVar5 = 0x7fffffff;
      iVar4 = 4;
      do {
        uVar2 = func_0x80040bb4((param_1[10] - (int)*(short *)(&DAT_80168ef8 + iVar4 * 4)) *
                                (param_1[10] - (int)*(short *)(&DAT_80168ef8 + iVar4 * 4)) +
                                (param_1[0xc] - (int)*(short *)(&DAT_80168efa + iVar4 * 4)) *
                                (param_1[0xc] - (int)*(short *)(&DAT_80168efa + iVar4 * 4)));
        if (uVar2 < uVar5) {
          *(char *)((int)param_1 + 0x2b7) = (char)iVar4;
          uVar5 = uVar2;
        }
        bVar1 = iVar4 != 0;
        iVar4 = iVar4 + -1;
      } while (bVar1);
    }
    else {
      uVar5 = 0x7fffffff;
      iVar4 = 1;
      do {
        uVar2 = func_0x80040bb4((param_1[10] - (int)(short)(&DAT_80168ef0)[iVar4 * 2]) *
                                (param_1[10] - (int)(short)(&DAT_80168ef0)[iVar4 * 2]) +
                                (param_1[0xc] - (int)(short)(&DAT_80168ef2)[iVar4 * 2]) *
                                (param_1[0xc] - (int)(short)(&DAT_80168ef2)[iVar4 * 2]));
        if (uVar2 < uVar5) {
          *(char *)((int)param_1 + 0x2b7) = (char)iVar4;
          uVar5 = uVar2;
        }
        bVar1 = iVar4 != 0;
        iVar4 = iVar4 + -1;
      } while (bVar1);
    }
    *(ushort *)(param_1 + 0xae) = *(ushort *)(param_1 + 0xae) | 8;
  case 1:
    iVar4 = 2;
    if (_DAT_800e8caa == 3) {
      iVar4 = 5;
      iVar7 = 8;
      puVar6 = &DAT_80168f3c;
      do {
        iVar3 = func_0x80032b10(param_1 + 10,puVar6);
        if (iVar3 != 0) {
          *(undefined1 *)((int)param_1 + 6) = 2;
          *(undefined2 *)((int)param_1 + 0x1f6) = *(undefined2 *)(&UNK_80168fdc + iVar7);
        }
        iVar7 = iVar7 + -2;
        iVar4 = iVar4 + -1;
        puVar6 = puVar6 + -8;
      } while (iVar4 != 0);
    }
    else {
      iVar7 = 2;
      puVar6 = &DAT_80168f14;
      do {
        iVar3 = func_0x80032b10(param_1 + 10,puVar6);
        if (iVar3 != 0) {
          *(undefined1 *)((int)param_1 + 6) = 2;
          *(undefined2 *)((int)param_1 + 0x1f6) = *(undefined2 *)(&DAT_80168fd8 + iVar7);
        }
        iVar7 = iVar7 + -2;
        iVar4 = iVar4 + -1;
        puVar6 = puVar6 + -8;
      } while (iVar4 != 0);
    }
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x98),(int)*(short *)((int)param_1 + 0x262),
                    0x10);
LAB_80164670:
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x80);
    func_0x80032b5c(param_1,0);
    *(undefined2 *)((int)param_1 + 0x1f2) = 0;
    break;
  case 2:
    func_0x80032ef4(param_1,(int)*(short *)((int)param_1 + 0x1f6),0x20);
    if (_DAT_800e8caa == 3) {
      iVar4 = func_0x80032f64(param_1,(int)*(short *)((int)param_1 + 0x1f6),0x10);
      if ((iVar4 == 0) && ((param_1[0x6b] & 1) != 0)) goto LAB_80164654;
    }
    else {
      iVar4 = func_0x80032f64(param_1,(int)*(short *)((int)param_1 + 0x1f6),0x10);
      if ((iVar4 == 0) && (((param_1[0x6b] & 1) != 0 && (-0x2134 < (int)param_1[10])))) {
LAB_80164654:
        *(undefined1 *)((int)param_1 + 6) = 3;
        *param_1 = *param_1 | 8;
      }
    }
    goto LAB_80164670;
  case 3:
    param_1[0x7a] = 0x10001f00;
    *(undefined1 *)((int)param_1 + 6) = 4;
    *(undefined2 *)((int)param_1 + 0x1f2) = 0xffff;
  case 4:
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar4 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar4 != 0) {
      *(undefined1 *)((int)param_1 + 6) = 5;
    }
    func_0x80032b5c(param_1,0);
    break;
  default:
    break;
  }
  return;
}
