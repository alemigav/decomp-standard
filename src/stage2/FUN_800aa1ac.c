/* FUN_800aa1ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aa1ac  body 0x800aa1ac..0x800aa4f7  size 844 B
 * body sha256 0f00f538069a017e9c1b72057ff2f615aaf62a0fc0fcf794d8cedbd00280c278
 * provider record sha256 88cbb65d0ed75af5c29fd4dea783382e4644eb99041bed414bb86528cdae8156
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800aa1ac(void)

{
  char cVar2;
  int iVar1;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  float fVar7;
  undefined8 uVar8;
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30 [2];
  
  DAT_801486b0 = 0;
  DAT_80148a40 = 0;
  DAT_80148bd0 = 0;
  if (_DAT_80148bd4 != (int *)0x0) {
    uVar8 = 0;
    piVar5 = _DAT_80148bd4;
    do {
      piVar6 = (int *)*piVar5;
      if ((piVar5[2] & 0x40000U) != 0) {
        if (piVar6 != (int *)0x0) {
          piVar6[1] = piVar5[1];
        }
        if ((int *)piVar5[1] == (int *)0x0) {
          _DAT_80148bd4 = (int *)*piVar5;
        }
        else {
          *(int *)piVar5[1] = *piVar5;
        }
        piVar5[2] = (uint)*(ushort *)((int)piVar5 + 10);
        if (piVar5[0xd] != -1) {
          FUN_800a8248();
        }
        goto LAB_800aa4bc;
      }
      if ((piVar5[2] & 0x20001U) != 0) {
        FUN_800a9600(piVar5,&local_40,&local_3c,&local_38,&local_34,local_30);
      }
      uVar3 = piVar5[2];
      if ((uVar3 & 0x80000) == 0) {
        if ((uVar3 & 0x20000) == 0) {
          iVar1 = FUN_800b230c(piVar5[0xd]);
          piVar5[0xd] = iVar1;
          if (iVar1 != -1) goto LAB_800aa394;
          uVar4 = piVar5[2];
          uVar3 = uVar4 | 0x20000;
          if ((uVar4 & 2) == 0) {
            uVar3 = uVar4 | 0x40000;
          }
LAB_800aa390:
          piVar5[2] = uVar3;
LAB_800aa394:
          if (piVar5[0xd] != -1) {
            if ((piVar5[2] & 1U) != 0) {
              FUN_800a9ce4(piVar5,local_40);
            }
            if ((local_40 == (float)uVar8) && ((piVar5[2] & 4U) != 0)) {
              FUN_800a8248(piVar5[0xd]);
              uVar3 = piVar5[2];
              piVar5[0xd] = -1;
              if ((uVar3 & 2) == 0) {
                piVar5[2] = uVar3 | 0x40000;
              }
              else {
                piVar5[2] = uVar3 | 0x80000;
              }
            }
            else {
              FUN_800a9a98(piVar5,local_40,local_38,local_34,local_30[0],local_3c);
            }
          }
          if (((piVar5[2] & 0x100000U) != 0) &&
             (fVar7 = (float)piVar5[0x10], piVar5[0x10] = (int)(fVar7 + 0.3), 1.0 <= fVar7 + 0.3)) {
            uVar3 = piVar5[2] & 0xffefffff;
            goto LAB_800aa4b4;
          }
        }
        else {
          if ((local_40 == (float)uVar8) && ((uVar3 & 4) != 0)) {
            uVar3 = uVar3 & 0xfffdffff | 0x80000;
            goto LAB_800aa390;
          }
          if ((piVar5[2] & 1U) != 0) {
            cVar2 = FUN_800a9e58(piVar5,local_40,local_38,local_34,local_30[0],local_3c);
            if (cVar2 != '\0') goto LAB_800aa4bc;
            goto LAB_800aa394;
          }
          iVar1 = FUN_800a83b4(*(undefined2 *)(piVar5 + 0xf),0x7f,0x40);
          piVar5[0xd] = iVar1;
          if (iVar1 != -1) goto LAB_800aa394;
          if ((piVar5[2] & 2U) == 0) {
            uVar3 = piVar5[2] & 0xfffdffffU | 0x40000;
            goto LAB_800aa390;
          }
        }
      }
      else {
        if (local_40 == (float)uVar8) goto LAB_800aa4bc;
        uVar3 = uVar3 & 0xfff7ffff | 0x20000;
LAB_800aa4b4:
        piVar5[2] = uVar3;
      }
LAB_800aa4bc:
      piVar5 = piVar6;
    } while (piVar6 != (int *)0x0);
  }
  FUN_800aa008();
  return;
}
