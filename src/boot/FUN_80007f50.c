/* FUN_80007f50
 * image   boot (boot), base 0x80000480
 * address 0x80007f50  body 0x80007f50..0x8000810f  size 448 B
 * body sha256 782d58bd2f9a0f46c2280b538f3c4951c7123ddb9dc03ef5c19c09f985ab105e
 * provider record sha256 d271d46b28653916347b4536280770ad73c80b98192ce4da1f1344cf419ce378
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80007f50(int param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 local_40;
  undefined4 local_3c [8];
  char local_1a;
  
  puVar10 = (undefined4 *)&DAT_80016470;
  uVar1 = 5;
  if (*(int *)(*(int *)(param_1 + 8) * 4 + -0x7ffed720) != 0) {
    FUN_8000cfb4();
    DAT_80014fe0 = 3;
    FUN_8000d1f0(1,*(int *)(param_1 + 8) * 0x40 + -0x7ffe9cb0);
    osRecvMesg(*(undefined4 *)(param_1 + 4),0,1);
    FUN_8000d1f0(0,&DAT_80016470);
    osRecvMesg(*(undefined4 *)(param_1 + 4),0,1);
    iVar5 = *(int *)(param_1 + 8);
    if ((iVar5 != 0) && (iVar3 = 0, 0 < iVar5)) {
      do {
        iVar3 = iVar3 + 1;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      } while (iVar3 < iVar5);
    }
    puVar8 = &local_40;
    puVar9 = puVar10 + 8;
    if (((uint)puVar10 & 3) == 0) {
      do {
        uVar4 = puVar10[1];
        uVar6 = puVar10[2];
        uVar7 = puVar10[3];
        *puVar8 = *puVar10;
        puVar8[1] = uVar4;
        puVar8[2] = uVar6;
        puVar8[3] = uVar7;
        puVar10 = puVar10 + 4;
        puVar8 = puVar8 + 4;
      } while (puVar10 != puVar9);
    }
    else {
      do {
        uVar4 = puVar10[1];
        uVar6 = puVar10[2];
        uVar7 = puVar10[3];
        *puVar8 = *puVar10;
        puVar8[1] = uVar4;
        puVar8[2] = uVar6;
        puVar8[3] = uVar7;
        puVar10 = puVar10 + 4;
        puVar8 = puVar8 + 4;
      } while (puVar10 != puVar9);
    }
    uVar4 = puVar10[1];
    *puVar8 = *puVar10;
    puVar8[1] = uVar4;
    uVar1 = (local_40._2_1_ & 0xc0) >> 4;
    if ((uVar1 == 0) && (cVar2 = FUN_80008f78(&DAT_80016450), cVar2 != local_1a)) {
      uVar1 = 4;
    }
    FUN_8000d020();
  }
  return uVar1;
}
