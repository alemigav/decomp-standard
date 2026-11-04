/* FUN_80009640
 * image   boot (boot), base 0x80000480
 * address 0x80009640  body 0x80009640..0x800099cf  size 912 B
 * body sha256 4108220410634dc5b9be9bf97f7bf96401a87fa8b4dbea3add89f06dc50b9a44
 * provider record sha256 a12b9fc52fe4a5319c827a530ec17f45683962b93972fe297b489d95e0da7b6f
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80009640(uint *param_1,short param_2,int param_3,undefined1 *param_4,undefined1 *param_5,
                int param_6,int *param_7)

{
  undefined2 uVar1;
  byte bVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  undefined2 local_288 [128];
  byte local_188 [256];
  int local_88;
  short local_84;
  ushort local_82;
  undefined2 local_7e;
  undefined1 local_7c [4];
  undefined1 local_78 [16];
  int local_68;
  int local_64;
  int local_60;
  int local_5c [2];
  short local_52;
  int local_4c;
  byte local_41;
  ushort local_3a;
  undefined2 *local_2c;
  
  iVar10 = 0;
  iVar9 = 0;
  local_41 = 0;
  if (param_2 != 0 && param_3 != 0) {
    iVar7 = param_6 + 0xff;
    if (iVar7 < 0) {
      iVar7 = param_6 + 0x1fe;
    }
    iVar7 = iVar7 >> 8;
    if ((*param_1 & 1) != 0) {
      local_52 = param_2;
      local_4c = param_3;
      iVar3 = FUN_8000a2d0(param_1);
      if (iVar3 == 2) {
        return 2;
      }
      iVar3 = FUN_8000bbf0(param_1,param_2,local_4c,param_4,param_5,param_7);
      if ((iVar3 != 0) && (iVar3 != 5)) {
        return iVar3;
      }
      if (*param_7 != -1) {
        return 9;
      }
      FUN_8000a900(param_1,&local_68);
      if (local_68 < param_6) {
        return 7;
      }
      if (iVar7 != 0) {
        iVar3 = FUN_8000bbf0(param_1,0,0,0,0,param_7);
        if ((iVar3 != 0) && (iVar3 != 5)) {
          return iVar3;
        }
        if (*param_7 == -1) {
          return 8;
        }
        bVar8 = 0;
        if (*(char *)(param_1 + 0x19) != '\0') {
          local_2c = local_288;
          bVar8 = 0;
          do {
            iVar3 = FUN_8000a394(param_1,local_288,0,bVar8);
            if ((iVar3 != 0) ||
               (iVar3 = FUN_800099d0(param_1,local_288,iVar7,&local_64,bVar8,&local_60,local_5c),
               iVar3 != 0)) {
              return iVar3;
            }
            if (local_64 != -1) {
              if (iVar9 == 0) {
                local_3a = (ushort)bVar8 << 8 | (ushort)local_64 & 0xff;
              }
              else {
                local_188[iVar10 * 2] = bVar8;
                bVar2 = local_41;
                local_188[iVar10 * 2 + 1] = (byte)local_64;
                iVar10 = FUN_8000a394(param_1,local_188,1,bVar2);
                if (iVar10 != 0) {
                  return iVar10;
                }
              }
              iVar10 = 0;
              puVar4 = local_2c;
              pbVar6 = local_188;
              do {
                uVar1 = *puVar4;
                puVar4 = puVar4 + 1;
                iVar10 = iVar10 + 1;
                *(undefined2 *)pbVar6 = uVar1;
                pbVar6 = pbVar6 + 2;
              } while (iVar10 < 0x80);
              iVar9 = iVar9 + 1;
              iVar10 = local_5c[0];
              local_41 = bVar8;
              if (iVar7 <= local_60) {
                iVar7 = 0;
                break;
              }
              iVar7 = iVar7 - local_60;
            }
            bVar8 = bVar8 + 1;
          } while (bVar8 < *(byte *)(param_1 + 0x19));
        }
        if (0 < iVar7) {
          return 3;
        }
        if (local_64 == -1) {
          return 3;
        }
        local_188[iVar10 * 2] = bVar8;
        bVar8 = local_41;
        local_188[iVar10 * 2 + 1] = (byte)local_64;
        iVar10 = FUN_8000a394(param_1,local_188,1,bVar8);
        puVar5 = local_78;
        if (iVar10 != 0) {
          return iVar10;
        }
        local_82 = local_3a;
        local_84 = local_52;
        local_7e = 0;
        local_88 = local_4c;
        do {
          *puVar5 = *param_4;
          puVar5 = puVar5 + 1;
          param_4 = param_4 + 1;
        } while ((int)puVar5 < (int)&local_68);
        puVar5 = local_7c;
        do {
          *puVar5 = *param_5;
          puVar5 = puVar5 + 1;
          param_5 = param_5 + 1;
        } while ((int)puVar5 < (int)local_78);
        iVar10 = FUN_80008b70(param_1[1],param_1[2],param_1[0x17] + *param_7 & 0xffff,&local_88,0);
        return iVar10;
      }
    }
  }
  return 5;
}
