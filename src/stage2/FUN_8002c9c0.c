/* FUN_8002c9c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002c9c0  body 0x8002c9c0..0x8002cb53  size 404 B
 * body sha256 001183961ea0cc762e37ba90a6a71fc70162e77289e1f09e58866757d1b6ad70
 * provider record sha256 9bb9ee9e16e63eb4b46176916c7339c31f1d6a2d63a2d2367c5ccd0e31c3c299
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002c9c0(int *param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  puVar4 = (undefined4 *)param_1[5];
  pbVar3 = (byte *)*puVar4;
  iVar2 = puVar4[1];
  while( true ) {
    if (iVar2 == 0) {
      iVar2 = (*(code *)puVar4[3])(param_1);
      if (iVar2 == 0) {
        return 0;
      }
      pbVar3 = (byte *)*puVar4;
      iVar2 = puVar4[1];
    }
    bVar1 = *pbVar3;
    while( true ) {
      iVar2 = iVar2 + -1;
      pbVar3 = pbVar3 + 1;
      if (bVar1 == 0xff) break;
      *(int *)(param_1[0x5d] + 0x5c) = *(int *)(param_1[0x5d] + 0x5c) + 1;
      *puVar4 = pbVar3;
      puVar4[1] = iVar2;
      if (iVar2 == 0) {
        iVar2 = (*(code *)puVar4[3])(param_1);
        if (iVar2 == 0) {
          return 0;
        }
        pbVar3 = (byte *)*puVar4;
        iVar2 = puVar4[1];
      }
      bVar1 = *pbVar3;
    }
    do {
      if (iVar2 == 0) {
        iVar2 = (*(code *)puVar4[3])(param_1);
        if (iVar2 == 0) {
          return 0;
        }
        pbVar3 = (byte *)*puVar4;
        iVar2 = puVar4[1];
      }
      iVar2 = iVar2 + -1;
      uVar5 = (uint)*pbVar3;
      pbVar3 = pbVar3 + 1;
    } while (uVar5 == 0xff);
    if (uVar5 != 0) break;
    *(int *)(param_1[0x5d] + 0x5c) = *(int *)(param_1[0x5d] + 0x5c) + 2;
    *puVar4 = pbVar3;
    puVar4[1] = iVar2;
  }
  if (*(int *)(param_1[0x5d] + 0x5c) != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x67;
    *(undefined4 *)(*param_1 + 0x18) = *(undefined4 *)(param_1[0x5d] + 0x5c);
    *(uint *)(*param_1 + 0x1c) = uVar5;
    (**(code **)(*param_1 + 4))(param_1,0xffffffff);
    *(undefined4 *)(param_1[0x5d] + 0x5c) = 0;
  }
  param_1[0x58] = uVar5;
  *puVar4 = pbVar3;
  puVar4[1] = iVar2;
  return 1;
}
