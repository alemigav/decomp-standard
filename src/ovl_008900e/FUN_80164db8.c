/* FUN_80164db8
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80164db8  body 0x80164db8..0x8016517b  size 964 B
 * body sha256 8085a5857df1a8a63afee158f51554a3a8855a35718e744c5e5b655bf9fb5709
 * provider record sha256 115c8c10d8e029277fba40d823558e2f4b8a3c42561ef22858da5984d56d3c46
 * callees 9 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164db8(uint *param_1)

{
  short sVar1;
  bool bVar2;
  char cVar4;
  ushort uVar3;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int unaff_s2;
  int iVar8;
  int local_28;
  uint local_24;
  int local_20;
  
  iVar8 = 0x7fffffff;
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    *(undefined1 *)(param_1 + 0x7a) = 1;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 1:
    if ((param_1[0xb2] & 0x20000) != 0) {
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
switchD_80164e2c_caseD_2:
      *(undefined1 *)((int)param_1 + 0x2ce) = 4;
      *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) | 2;
      func_0x8006b28c(0xf,0x200,0xffffffff);
      puVar7 = (uint *)&DAT_800e1068;
      do {
        uVar3 = func_0x8006a42c(param_1 + 10,*puVar7);
        if (uVar3 == 1) {
          unaff_s2 = (int)*(short *)(*puVar7 + 2) - param_1[0xc];
LAB_80164f60:
          if (unaff_s2 < 0) {
            unaff_s2 = -unaff_s2;
          }
          bVar2 = unaff_s2 < iVar8;
        }
        else if (uVar3 < 2) {
          bVar2 = unaff_s2 < iVar8;
          if (uVar3 == 0) {
            uVar6 = param_1[10];
            iVar5 = (int)*(short *)*puVar7 + (uint)(ushort)((short *)*puVar7)[2];
LAB_80164f5c:
            unaff_s2 = uVar6 - iVar5;
            goto LAB_80164f60;
          }
        }
        else {
          if (uVar3 == 2) {
            unaff_s2 = (int)*(short *)*puVar7 - param_1[10];
            goto LAB_80164f60;
          }
          bVar2 = unaff_s2 < iVar8;
          if (uVar3 == 3) {
            uVar6 = param_1[0xc];
            iVar5 = (int)*(short *)(*puVar7 + 2) + (uint)*(ushort *)(*puVar7 + 6);
            goto LAB_80164f5c;
          }
        }
        if (bVar2) {
          param_1[0xb0] = *puVar7;
          iVar8 = unaff_s2;
        }
        puVar7 = puVar7 + 1;
      } while (*puVar7 != 0);
      *(ushort *)(param_1 + 0xb4) =
           *(short *)param_1[0xb0] + ((ushort)((short *)param_1[0xb0])[2] >> 1);
      uVar3 = *(ushort *)(param_1[0xb0] + 6);
      sVar1 = *(short *)(param_1[0xb0] + 2);
      *(undefined1 *)((int)param_1 + 0x1e9) = 1;
      *(undefined2 *)(param_1 + 0x7d) = 0;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
      *(ushort *)(param_1 + 0xb5) = sVar1 + (uVar3 >> 1);
      goto switchD_80164e2c_caseD_3;
    }
    cVar4 = func_0x80036be4(param_1,6,0xf,0,0x8980000,0);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar4;
    break;
  case 2:
    goto switchD_80164e2c_caseD_2;
  case 3:
    goto switchD_80164e2c_caseD_3;
  case 4:
    iVar8 = func_0x80036be4(param_1,0x11,0xf,0,0x8980000,0);
    if (iVar8 != 0) {
      FUN_801620a4(param_1);
      *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) & 0xffbf;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
      return;
    }
    goto LAB_80165158;
  case 5:
    iVar8 = entry();
    if (iVar8 != 0) {
      *(undefined1 *)((int)param_1 + 0x2ce) = 1;
      *param_1 = *param_1 & 0xfffffffb;
      *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) & 0xfffd;
      FUN_80161e44(param_1);
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    }
    goto LAB_80165104;
  case 6:
    iVar8 = func_0x80036be4(param_1,0x11,0xf,0,0x8980000,0);
    if (iVar8 != 0) {
      FUN_801620a4(param_1);
      param_1[1] = 0x1150000;
      *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) & 0xff7f;
      return;
    }
LAB_80165158:
    FUN_80162000(param_1);
    break;
  default:
    break;
  }
  goto switchD_80164e2c_default;
switchD_80164e2c_caseD_3:
  local_28 = (int)*(short *)(param_1 + 0xb4);
  local_24 = param_1[0xb];
  local_20 = (int)*(short *)(param_1 + 0xb5);
  func_0x80036f64(param_1,&local_28,0x40);
  if ((param_1[0x6b] & 1) != 0) {
    *(short *)((int)param_1 + 0x1f6) = *(short *)((int)param_1 + 0x1f6) + 1;
  }
  if (0xb3 < *(short *)(param_1 + 0x7d)) {
    param_1[1] = 0x1000000;
  }
  iVar8 = entry();
  if (iVar8 != 0) {
    FUN_80161e44(param_1);
    *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) | 0xc0;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    *param_1 = *param_1 | 4;
  }
LAB_80165104:
  func_0x80036d14(param_1,0,0xf,0);
switchD_80164e2c_default:
  return;
}
