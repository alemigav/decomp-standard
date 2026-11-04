/* FUN_80008b70
 * image   boot (boot), base 0x80000480
 * address 0x80008b70  body 0x80008b70..0x80008d8f  size 544 B
 * body sha256 becdc95474b664d4bc5e7c00e0817f6cbd38d56913ea65769856e294b7669309
 * provider record sha256 728b3d335d9b67a8e54d2ddd037920c162008d1bb74453603e751ed7a63a2cc0
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80008b70(undefined4 param_1,int param_2,ushort param_3,undefined4 param_4,int param_5)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 local_50;
  undefined4 local_4c [8];
  char local_2a;
  
  iVar10 = 2;
  if ((param_5 != 1 && param_3 < 7) && (param_3 != 0)) {
    return 0;
  }
  FUN_8000cfb4();
  DAT_80014fe0 = 3;
  FUN_80008d90(param_2,param_3,param_4);
  FUN_8000d1f0(1,&DAT_80016470);
  osRecvMesg(param_1,0,1);
  do {
    FUN_8000d1f0(0,&DAT_80016470);
    osRecvMesg(param_1,0,1);
    puVar5 = (undefined4 *)&DAT_80016470;
    if ((param_2 != 0) && (iVar3 = 0, 0 < param_2)) {
      do {
        iVar3 = iVar3 + 1;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      } while (iVar3 < param_2);
    }
    puVar8 = &local_50;
    puVar9 = puVar5 + 8;
    if (((uint)puVar5 & 3) == 0) {
      do {
        uVar4 = puVar5[1];
        uVar6 = puVar5[2];
        uVar7 = puVar5[3];
        *puVar8 = *puVar5;
        puVar8[1] = uVar4;
        puVar8[2] = uVar6;
        puVar8[3] = uVar7;
        puVar5 = puVar5 + 4;
        puVar8 = puVar8 + 4;
      } while (puVar5 != puVar9);
    }
    else {
      do {
        uVar4 = puVar5[1];
        uVar6 = puVar5[2];
        uVar7 = puVar5[3];
        *puVar8 = *puVar5;
        puVar8[1] = uVar4;
        puVar8[2] = uVar6;
        puVar8[3] = uVar7;
        puVar5 = puVar5 + 4;
        puVar8 = puVar8 + 4;
      } while (puVar5 != puVar9);
    }
    uVar4 = puVar5[1];
    *puVar8 = *puVar5;
    puVar8[1] = uVar4;
    if ((local_50._2_1_ & 0xc0) == 0) {
      cVar2 = FUN_80008f78(param_4);
      iVar3 = 0;
      if (cVar2 != local_2a) {
        iVar3 = FUN_8000aa10(param_1,param_2);
        if (iVar3 != 0) {
LAB_80008d60:
          FUN_8000d020();
          return iVar3;
        }
        iVar3 = 4;
      }
    }
    else {
      iVar3 = 1;
    }
    if ((iVar3 != 4) || (bVar1 = iVar10 < 0, iVar10 = iVar10 + -1, bVar1)) goto LAB_80008d60;
  } while( true );
}
