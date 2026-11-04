/* FUN_8002bd80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002bd80  body 0x8002bd80..0x8002bf73  size 500 B
 * body sha256 8610fb60ec39b7af02ea404b3090162062e6c00834365dc5b39dda910dd1238d
 * provider record sha256 f17775bbf95a3ba98cd11ba36757683b866995259f015a9560af019d9dbf742e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002bd80(int *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  puVar6 = (undefined4 *)param_1[5];
  puVar4 = (undefined1 *)*puVar6;
  iVar3 = puVar6[1];
  if (iVar3 == 0) {
    iVar3 = (*(code *)puVar6[3])();
    if (iVar3 == 0) {
      return 0;
    }
    puVar4 = (undefined1 *)*puVar6;
    iVar3 = puVar6[1];
  }
  iVar3 = iVar3 + -1;
  uVar1 = *puVar4;
  pbVar5 = puVar4 + 1;
  if (iVar3 == 0) {
    iVar3 = (*(code *)puVar6[3])(param_1);
    if (iVar3 == 0) {
      return 0;
    }
    pbVar5 = (byte *)*puVar6;
    iVar3 = puVar6[1];
  }
  uVar9 = (uint)CONCAT11(uVar1,*pbVar5);
  do {
    uVar9 = uVar9 - 2;
    pbVar5 = pbVar5 + 1;
    iVar3 = iVar3 + -1;
    if ((int)uVar9 < 1) {
      *puVar6 = pbVar5;
      puVar6[1] = iVar3;
      return 1;
    }
    if (iVar3 == 0) {
      iVar3 = (*(code *)puVar6[3])(param_1);
      if (iVar3 == 0) {
        return 0;
      }
      pbVar5 = (byte *)*puVar6;
      iVar3 = puVar6[1];
    }
    iVar3 = iVar3 + -1;
    uVar7 = (uint)*pbVar5;
    pbVar5 = pbVar5 + 1;
    if (iVar3 == 0) {
      iVar3 = (*(code *)puVar6[3])(param_1);
      if (iVar3 == 0) {
        return 0;
      }
      pbVar5 = (byte *)*puVar6;
      iVar3 = puVar6[1];
    }
    bVar2 = *pbVar5;
    uVar8 = (uint)bVar2;
    *(undefined4 *)(*param_1 + 0x14) = 0x47;
    *(uint *)(*param_1 + 0x18) = uVar7;
    *(uint *)(*param_1 + 0x1c) = uVar8;
    (**(code **)(*param_1 + 4))(param_1,1);
    if (0x1f < uVar7) {
      *(undefined4 *)(*param_1 + 0x14) = 0x15;
      *(uint *)(*param_1 + 0x18) = uVar7;
      (**(code **)*param_1)(param_1);
    }
    if (uVar7 < 0x10) {
      *(char *)((int)param_1 + uVar7 + 0xb4) = (char)(uVar8 & 0xf);
      *(char *)((int)param_1 + uVar7 + 0xc4) = (char)((int)uVar8 >> 4);
      if ((uint)((int)uVar8 >> 4) < (uVar8 & 0xf)) {
        *(undefined4 *)(*param_1 + 0x14) = 0x16;
        *(uint *)(*param_1 + 0x18) = uVar8;
        (**(code **)*param_1)(param_1);
      }
    }
    else {
      *(byte *)((int)param_1 + uVar7 + 0xc4) = bVar2;
    }
  } while( true );
}
