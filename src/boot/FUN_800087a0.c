/* FUN_800087a0
 * image   boot (boot), base 0x80000480
 * address 0x800087a0  body 0x800087a0..0x800089d3  size 564 B
 * body sha256 e80e5b41e8014e6d05844adf99948cce64c4e4c503c753883d59d25e9aba8e36
 * provider record sha256 d58923a2b4282a681f28d1d5849e4413e490360033c6a4a6462533baca58fb07
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800087a0(undefined4 param_1,int param_2,undefined2 param_3,undefined1 *param_4)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50 [7];
  byte local_32 [10];
  
  iVar12 = 2;
  FUN_8000cfb4();
  DAT_80014fe0 = 2;
  FUN_800089d4(param_2,param_3);
  FUN_8000d1f0(1,&DAT_80016470);
  osRecvMesg(param_1,0,1);
  do {
    FUN_8000d1f0(0,&DAT_80016470);
    osRecvMesg(param_1,0,1);
    puVar11 = (undefined4 *)&DAT_80016470;
    if ((param_2 != 0) && (iVar4 = 0, 0 < param_2)) {
      do {
        iVar4 = iVar4 + 1;
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      } while (iVar4 < param_2);
    }
    puVar9 = &local_58;
    puVar10 = puVar11 + 8;
    if (((uint)puVar11 & 3) == 0) {
      do {
        uVar5 = puVar11[1];
        uVar7 = puVar11[2];
        uVar8 = puVar11[3];
        *puVar9 = *puVar11;
        puVar9[1] = uVar5;
        puVar9[2] = uVar7;
        puVar9[3] = uVar8;
        puVar11 = puVar11 + 4;
        puVar9 = puVar9 + 4;
      } while (puVar11 != puVar10);
    }
    else {
      do {
        uVar5 = puVar11[1];
        uVar7 = puVar11[2];
        uVar8 = puVar11[3];
        *puVar9 = *puVar11;
        puVar9[1] = uVar5;
        puVar9[2] = uVar7;
        puVar9[3] = uVar8;
        puVar11 = puVar11 + 4;
        puVar9 = puVar9 + 4;
      } while (puVar11 != puVar10);
    }
    uVar5 = puVar11[1];
    *puVar9 = *puVar11;
    puVar9[1] = uVar5;
    if ((local_58._2_1_ & 0xc0) == 0) {
      bVar3 = FUN_80008f78((int)&local_54 + 2);
      if (bVar3 == local_32[0]) {
        puVar6 = (undefined1 *)((int)&local_54 + 2);
        do {
          uVar2 = *puVar6;
          puVar6 = puVar6 + 1;
          *param_4 = uVar2;
          param_4 = param_4 + 1;
        } while ((int)puVar6 < (int)local_32);
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_8000aa10(param_1,param_2);
        if (iVar4 != 0) {
LAB_8000899c:
          FUN_8000d020();
          return iVar4;
        }
        iVar4 = 4;
      }
    }
    else {
      iVar4 = 1;
    }
    if ((iVar4 != 4) || (bVar1 = iVar12 < 0, iVar12 = iVar12 + -1, bVar1)) goto LAB_8000899c;
  } while( true );
}
