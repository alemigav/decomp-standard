/* FUN_8005fb54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005fb54  body 0x8005fb54..0x8005fcdf  size 396 B
 * body sha256 9e7b237c3deb8f27cc61ef48f186877227c5287b6e08b76f0cd959a5313a2d38
 * provider record sha256 c4c957adf6518fa59a0f2ff5f63cef06dfe066db6e2f15307b1ea966bc0d8b77
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
uint * FUN_8005fb54(int *param_1,short param_2,uint param_3,short param_4)

{
  uint uVar1;
  short sVar4;
  int iVar2;
  uint *puVar3;
  uint *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint *puVar8;
  int local_30 [2];
  
  if (DAT_800e1126 == '\0') {
    puVar3 = DAT_800df938;
  }
  else {
    puVar6 = &DAT_800e13f0;
    puVar8 = (uint *)0x0;
    do {
      puVar5 = (uint *)*puVar6;
      uVar7 = param_3;
      puVar3 = puVar8;
      if (((*puVar5 & 1) != 0) && ((*(ushort *)((int)puVar5 + 0x1aa) & 0xe000) == 0)) {
        local_30[0] = *param_1 - puVar5[10];
        uVar1 = FUN_80040bb4(local_30[0] * local_30[0] +
                             (param_1[2] - puVar5[0xc]) * (param_1[2] - puVar5[0xc]));
        sVar4 = FUN_80032d14((int)(short)*param_1,(int)*(short *)((int)param_1 + 10),
                             (int)*(short *)((int)puVar5 + 0x2a),(int)*(short *)((int)puVar5 + 0x32)
                            );
        if ((-1 < *(short *)((int)puVar5 + 0x1f2)) &&
           ((iVar2 = FUN_8006087c((int)sVar4,(int)param_2,(int)param_4,local_30), iVar2 == 0 &&
            (uVar7 = uVar1, puVar3 = puVar5, param_3 <= uVar1)))) {
          uVar7 = param_3;
          puVar3 = puVar8;
        }
      }
      puVar6 = puVar6 + 1;
      param_3 = uVar7;
      puVar8 = puVar3;
    } while (puVar6 != DAT_800df93c);
    if (puVar3 == (uint *)0x0) {
      puVar3 = DAT_800df938;
    }
  }
  return puVar3;
}
