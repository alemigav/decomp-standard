/* FUN_80009cac
 * image   boot (boot), base 0x80000480
 * address 0x80009cac  body 0x80009cac..0x80009f8b  size 736 B
 * body sha256 5a331c126963c63f341ab0545974568f7ac8868a0e3a28f33ef774c1755c103c
 * provider record sha256 e257e414aa2fafb5baac450e27f2ba636ed04cd6c14adf9d326498f9935d721f
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80009cac(int param_1,int param_2,ushort *param_3)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  ushort *puVar8;
  byte *pbVar9;
  ushort *puVar10;
  int iVar11;
  byte local_68 [32];
  byte local_48 [32];
  undefined2 local_28 [4];
  
  if (*(char *)(param_1 + 0x65) != '\0') {
    *(undefined1 *)(param_1 + 0x65) = 0;
    iVar4 = FUN_8000a66c();
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  param_3[0] = 0xffff;
  param_3[1] = 0xffff;
  uVar5 = FUN_80007000();
  *(undefined4 *)(param_3 + 2) = uVar5;
  uVar5 = *(undefined4 *)(param_2 + 0xc);
  iVar4 = 0;
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_3 + 6) = uVar5;
  uVar5 = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(param_3 + 8) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_3 + 10) = uVar5;
  *(undefined1 *)(param_1 + 0x65) = 0;
  do {
    iVar6 = FUN_8000a66c(param_1);
    if (iVar6 != 0) {
      return iVar6;
    }
    iVar6 = FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),0,local_68);
    pbVar7 = local_68 + 1;
    if (iVar6 != 0) {
      return iVar6;
    }
    local_68[0] = (byte)iVar4 | 0x80;
    do {
      *pbVar7 = ~*pbVar7;
      pbVar7 = pbVar7 + 1;
    } while ((int)pbVar7 < (int)local_48);
    iVar6 = FUN_80008b70(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),0,local_68,0);
    if (iVar6 != 0) {
      return iVar6;
    }
    iVar6 = FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),0,local_48);
    iVar11 = 0;
    if (iVar6 != 0) {
      return iVar6;
    }
    pbVar7 = local_48;
    pbVar9 = local_68;
    do {
      if (*pbVar7 != *pbVar9) break;
      pbVar9 = pbVar9 + 1;
      iVar11 = iVar11 + 1;
      pbVar7 = pbVar7 + 1;
    } while (iVar11 < 0x20);
    if (iVar11 != 0x20) {
      *(undefined1 *)(param_1 + 0x65) = 0;
LAB_80009e48:
      iVar6 = FUN_8000a66c(param_1);
      if (iVar6 != 0) {
        return iVar6;
      }
      uVar3 = *(ushort *)(param_2 + 0x18);
      *(char *)(param_3 + 0xd) = (char)iVar4;
      param_3[0xc] = (ushort)(0 < iVar4) | uVar3 & 0xfffe;
      cVar1 = *(char *)(param_2 + 0x1b);
      puVar10 = param_3 + 0xe;
      param_3[0xf] = 0;
      param_3[0xe] = 0;
      *(char *)((int)param_3 + 0x1b) = cVar1;
      puVar8 = param_3;
      do {
        uVar3 = *puVar8;
        *puVar10 = *puVar10 + uVar3;
        puVar8 = puVar8 + 1;
        param_3[0xf] = param_3[0xf] + ~uVar3;
        iVar4 = 0;
      } while (puVar8 < puVar10);
      pbVar7 = local_68;
      local_28[0] = 1;
      local_28[1] = 3;
      local_28[2] = 4;
      local_28[3] = 6;
      do {
        iVar6 = FUN_80008b70(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                             *(undefined2 *)(pbVar7 + 0x40),param_3,1);
        iVar4 = iVar4 + 1;
        if (iVar6 != 0) {
          return iVar6;
        }
        pbVar7 = pbVar7 + 2;
      } while (iVar4 < 4);
      iVar4 = FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),1,local_68);
      if (iVar4 == 0) {
        pbVar7 = local_68;
        puVar8 = param_3 + 0x10;
        while (bVar2 = *(byte *)param_3, param_3 = (ushort *)((int)param_3 + 1), *pbVar7 == bVar2) {
          pbVar7 = pbVar7 + 1;
          if ((int)puVar8 <= (int)param_3) {
            return 0;
          }
        }
        iVar4 = 10;
      }
      return iVar4;
    }
    if (0 < iVar4) {
      *(undefined1 *)(param_1 + 0x65) = 0;
      iVar6 = FUN_8000a66c(param_1);
      if (iVar6 != 0) {
        return iVar6;
      }
      iVar6 = FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),0,local_68);
      if (iVar6 != 0) {
        return iVar6;
      }
      if (local_68[0] != 0x80) {
        *(undefined1 *)(param_1 + 0x65) = 0;
        goto LAB_80009e48;
      }
    }
    iVar4 = iVar4 + 1;
    if (0x3d < iVar4) {
      *(undefined1 *)(param_1 + 0x65) = 0;
      goto LAB_80009e48;
    }
    *(char *)(param_1 + 0x65) = (char)iVar4;
  } while( true );
}
