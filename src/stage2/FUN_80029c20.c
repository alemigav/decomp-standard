/* FUN_80029c20
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80029c20  body 0x80029c20..0x80029db3  size 404 B
 * body sha256 3ad1a59cfa916575aedf9e7770463d6babc65bc8155233bad46db976d4174c2d
 * provider record sha256 ae5bd09c5ff1c608ace19f9c0a99097f7218be816b70d7705d53090f30b57f15
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80029c20(uint *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  
  pbVar4 = (byte *)param_1[1];
  uVar3 = param_1[2];
  uVar6 = param_1[3];
  for (uVar5 = param_1[4]; (int)uVar5 < 0x19; uVar5 = uVar5 + 8) {
    if (*param_1 == 0) {
      if (uVar3 == 0) {
        iVar1 = (**(code **)(*(int *)(param_1[9] + 0x14) + 0xc))();
        if (iVar1 == 0) {
          return 0;
        }
        pbVar4 = (byte *)**(undefined4 **)(param_1[9] + 0x14);
        uVar3 = (*(undefined4 **)(param_1[9] + 0x14))[1];
      }
      uVar3 = uVar3 - 1;
      uVar2 = (uint)*pbVar4;
      pbVar4 = pbVar4 + 1;
      if (uVar2 == 0xff) {
        do {
          if (uVar3 == 0) {
            iVar1 = (**(code **)(*(int *)(param_1[9] + 0x14) + 0xc))();
            if (iVar1 == 0) {
              return 0;
            }
            pbVar4 = (byte *)**(undefined4 **)(param_1[9] + 0x14);
            uVar3 = (*(undefined4 **)(param_1[9] + 0x14))[1];
          }
          uVar3 = uVar3 - 1;
          uVar2 = (uint)*pbVar4;
          pbVar4 = pbVar4 + 1;
        } while (uVar2 == 0xff);
        if (uVar2 != 0) {
          *param_1 = uVar2;
          goto LAB_80029d10;
        }
        uVar2 = 0xff;
      }
    }
    else {
LAB_80029d10:
      if (param_2 <= (int)uVar5) break;
      if (*(int *)(((int *)param_1[9])[0x5e] + 0x24) == 0) {
        *(undefined4 *)(*(int *)param_1[9] + 0x14) = 0x68;
        (**(code **)(*(int *)param_1[9] + 4))((int *)param_1[9],0xffffffff);
        *(undefined4 *)(*(int *)(param_1[9] + 0x178) + 0x24) = 1;
        uVar2 = 0;
      }
      else {
        uVar2 = 0;
      }
    }
    uVar6 = uVar6 << 8 | uVar2;
  }
  param_1[1] = (uint)pbVar4;
  param_1[2] = uVar3;
  param_1[3] = uVar6;
  param_1[4] = uVar5;
  return 1;
}
