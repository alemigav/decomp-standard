/* FUN_8003a590
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a590  body 0x8003a590..0x8003a60b  size 124 B
 * body sha256 45a69095c641e5dca7b9f3440696f8d464107a0c611d58431eb6c08fa265d240
 * provider record sha256 58de80852194a1134ddd27ff6a07d3706abf112828b57ebe1d4c33f1aee6e99b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003a590(void)

{
  short sVar1;
  short sVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  short sVar9;
  uint uVar7;
  uint uVar8;
  undefined4 uVar10;
  short sVar11;
  uint uVar12;
  short sStack_40;
  short sStack_3e;
  undefined2 uStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  undefined4 local_28;
  undefined4 local_24;
  
  puVar3 = DAT_800ebb94;
  local_28 = 0xff380000;
  local_24 = 0x640032;
  switch(DAT_800ebb94[2]) {
  case 0:
    *(undefined2 *)(DAT_800ebb94 + 0x18) = *(undefined2 *)(DAT_800ebb94 + 0x12);
    DAT_80131781 = 1;
    iStack_38 = (int)*(short *)(puVar3 + 0x34);
    iStack_34 = (int)*(short *)(puVar3 + 0x36);
    iStack_30 = (int)*(short *)(puVar3 + 0x38);
    FUN_80077adc(0x1100001,&iStack_38);
    FUN_800609e0(0x120,(int)*(short *)(DAT_800ebb94 + 0x22),&local_28,0x3000e);
    sVar11 = 0;
    if (iStack_34 < iRam00000124) {
      iStack_34 = iRam00000124 - iStack_34;
LAB_8003a6ac:
      sVar11 = (short)(iStack_34 / 5);
    }
    else if (iRam00000124 < iStack_34) {
      iStack_34 = iStack_34 - iRam00000124;
      goto LAB_8003a6ac;
    }
    iStack_38 = iRam00000120 - *(short *)(DAT_800ebb94 + 0x34);
    if (iStack_38 < 0) {
      iStack_38 = -iStack_38;
    }
    iStack_34 = iRam00000124 - *(short *)(DAT_800ebb94 + 0x36);
    if (iStack_34 < 0) {
      iStack_34 = -iStack_34;
    }
    iStack_30 = iRam00000128 - *(short *)(DAT_800ebb94 + 0x38);
    if (iStack_30 < 0) {
      iStack_30 = -iStack_30;
    }
    iVar4 = FUN_80040bb4(iStack_38 * iStack_38 + iStack_30 * iStack_30);
    iVar5 = FUN_80040bb4(iStack_38 * iStack_38 + iStack_30 * iStack_30);
    uVar6 = FUN_80040bb4(iStack_34 * iStack_34 + iVar4 * iVar5);
    sVar9 = FUN_80078824((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38),
                         iRam00000120,iRam00000128);
    sVar1 = *(short *)(DAT_800ebb94 + 0x22);
    sStack_40 = *(short *)(DAT_800ebb94 + 0x2c);
    sStack_3e = *(short *)(DAT_800ebb94 + 0x2e);
    uVar6 = uVar6 / 0x1b0;
    uStack_3c = *(undefined2 *)(DAT_800ebb94 + 0x30);
    if (uVar6 == 0) {
      uVar6 = 1;
    }
    uVar12 = (uint)(iRam00000124 - *(short *)(DAT_800ebb94 + 0x36)) / uVar6;
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    do {
      uVar6 = uVar6 - 1;
      uVar7 = FUN_80038a20(0x6012600,((int)sVar9 - (int)sVar1) * 0x10000 >> 0x10,DAT_800ebb94 + 0x4c
                           ,&sStack_40);
      if ((uVar7 & 0xff) < 0xff) {
        iVar4 = (uVar7 & 0xff) * 0x7c;
        uVar7 = FUN_80033604();
        *(short *)(&DAT_800ebdec + iVar4) = (short)((uVar7 & 0xff) % 0x1e) * 10 + -0x96;
        uVar7 = FUN_80033604();
        *(short *)(&DAT_800ebdee + iVar4) = (short)((uVar7 & 0xff) % 0x32) * 0x28 + -1000;
        uVar7 = FUN_80033604();
        uVar8 = FUN_80033604();
        sVar2 = sVar11;
        if ((uVar8 & 2) != 0) {
          sVar2 = sVar11 + 0x800;
        }
        *(short *)(&DAT_800ebdf0 + iVar4) = (short)((uVar7 & 0xff) % 0x14) * 0x1e + 0x338 + sVar2;
      }
      else {
        uVar6 = 0;
      }
      sStack_3e = sStack_3e + 0x1b0;
      sStack_40 = sStack_40 - (short)uVar12;
    } while (uVar6 != 0);
    FUN_800274f8(0x100,0,7,1);
    uVar10 = 0x2000;
    break;
  case 1:
    uVar10 = 0x1800;
    break;
  case 2:
    uVar10 = 0x1600;
    break;
  case 3:
    FUN_80027650(0);
    goto LAB_8003aa04;
  case 4:
    FUN_800274f8(0x100,0,7,1);
    uVar10 = 0x1400;
    break;
  case 5:
    uVar10 = 0x1200;
    break;
  case 6:
    FUN_80027650(0);
    puVar3 = DAT_800ebb94;
    DAT_800ebb94[1] = 0;
    *puVar3 = 0;
    *(undefined2 *)(puVar3 + 0x18) = 0;
  default:
    goto LAB_8003aa04;
  }
  FUN_800275c0(0,uVar10,0x8421,0);
LAB_8003aa04:
  DAT_800ebb94[2] = DAT_800ebb94[2] + '\x01';
  return;
}
