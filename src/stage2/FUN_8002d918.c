/* FUN_8002d918
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002d918  body 0x8002d918..0x8002da4f  size 312 B
 * body sha256 1991d94ca094ac2b7a2dbbc99f8c192c63b40d4903a58f1d422349d98d491a54
 * provider record sha256 e9fb93642ae6404ddeda1f808a09e1f9e6b5839e9db2f7731e27c69b895f4fe6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002d918(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x580);
  *(int *)(param_1 + 0x114) = iVar1 + 0x100;
  FUN_8002fc00(iVar1,0,0x100);
  iVar4 = 0xff;
  puVar2 = (undefined1 *)(iVar1 + 0x1ff);
  do {
    *puVar2 = (char)iVar4;
    iVar4 = iVar4 + -1;
    puVar2 = puVar2 + -1;
  } while (-1 < iVar4);
  iVar4 = 0x80;
  puVar2 = (undefined1 *)(iVar1 + 0x200);
  do {
    *puVar2 = 0xff;
    iVar4 = iVar4 + 1;
    puVar2 = (undefined1 *)(iVar1 + 0x180 + iVar4);
  } while (iVar4 < 0x200);
  FUN_8002fc00(iVar1 + 0x380,0,0x180);
  puVar6 = *(undefined4 **)(param_1 + 0x114);
  puVar5 = (undefined4 *)(iVar1 + 0x500);
  puVar3 = puVar6 + 0x20;
  if ((((uint)puVar6 | (uint)puVar5) & 3) == 0) {
    do {
      uVar7 = puVar6[1];
      uVar8 = puVar6[2];
      uVar9 = puVar6[3];
      *puVar5 = *puVar6;
      puVar5[1] = uVar7;
      puVar5[2] = uVar8;
      puVar5[3] = uVar9;
      puVar6 = puVar6 + 4;
      puVar5 = puVar5 + 4;
    } while (puVar6 != puVar3);
  }
  else {
    do {
      uVar7 = puVar6[1];
      uVar8 = puVar6[2];
      uVar9 = puVar6[3];
      *puVar5 = *puVar6;
      puVar5[1] = uVar7;
      puVar5[2] = uVar8;
      puVar5[3] = uVar9;
      puVar6 = puVar6 + 4;
      puVar5 = puVar5 + 4;
    } while (puVar6 != puVar3);
  }
  return;
}
