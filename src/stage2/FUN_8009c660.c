/* FUN_8009c660
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009c660  body 0x8009c660..0x8009cce3  size 1668 B
 * body sha256 9f7a64a037f5af4e134d411283cc9310c1815cab0f3f27e95a5b682c06f3260d
 * provider record sha256 021e470bbfd4ab79a070a629f9a1aca76033e1ba005280e4ff7b901d22090b34
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8009c660(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined1 auStack_30 [8];
  undefined4 local_28;
  undefined1 local_24;
  short local_20 [4];
  
  iVar2 = DAT_800c52dc;
  _DAT_80012820 = DAT_8010b6fc;
  FUN_8004cd88(1);
  puVar5 = (undefined1 *)(iVar2 + 0x3b80fU & 0xfffffff0);
  DAT_8013263c = puVar5;
  if (puVar5 < (undefined1 *)(DAT_800c52dc + 0x4e400)) {
    *puVar5 = 0;
    while (puVar5 = puVar5 + 1, puVar5 < (undefined1 *)(DAT_800c52dc + 0x4e400)) {
      *puVar5 = 0;
    }
  }
  puVar5 = (undefined1 *)((uint)(puVar5 + 0xf) & 0xfffffff0);
  DAT_80132640 = puVar5;
  if (puVar5 < (undefined1 *)(DAT_800c52dc + 0x4e600)) {
    *puVar5 = 0;
    while (puVar5 = puVar5 + 1, puVar5 < (undefined1 *)(DAT_800c52dc + 0x4e600)) {
      *puVar5 = 0;
    }
  }
  DAT_80132630 = 0x140;
  DAT_8013262c = 0x140;
  DAT_80132634 = 0xf0;
  DAT_80132638 = 1;
  FUN_80082200(auStack_30,0,5);
  local_28 = 0x50a1518;
  local_24 = 0x18;
  FUN_8004ce90(0);
  FUN_800274e4(2,1);
  DAT_800e90f8 = 1;
  DAT_800e110c = DAT_800e110c | 0x10;
  FUN_800428e0(0xd0);
  DAT_800e9182 = 0;
  DAT_80132729 = 1;
  DAT_8013272b = 0;
  DAT_8013272e = 0;
  DAT_8013273a = 0;
  DAT_80132740 = 0;
  DAT_80132730 = 0;
  DAT_80132734 = 0;
  DAT_8013272c = 0;
  DAT_80132744 = 0;
  DAT_8013272a = 1;
  DAT_80132728 = 0;
  FUN_80026980(0);
  FUN_8004cd88(1);
  if ((DAT_800e10ec & 0x20000) == 0) {
    if ((DAT_800e10ec & 8) != 0) goto LAB_8009c8ac;
    local_20[0] = DAT_800e8b3b - 0xf;
    if (local_20[0] == 0) {
      if (-1 < (int)DAT_800e110c) goto LAB_8009c900;
LAB_8009c8f8:
      DAT_8013273c = 1;
    }
    else {
      if (local_20[0] == 1) {
        if (-1 < (int)DAT_800e110c) goto LAB_8009c920;
        goto LAB_8009c914;
      }
      FUN_8009cce4();
    }
  }
  else if ((DAT_800e10ec & 8) == 0) {
    if ((int)DAT_800e110c < 0) {
      if ((DAT_800e110c & 0x40000000) == 0) goto LAB_8009c8f8;
LAB_8009c914:
      DAT_8013273c = 3;
    }
    else if ((DAT_800e110c & 0x40000000) == 0) {
LAB_8009c900:
      DAT_8013273c = 0;
    }
    else {
LAB_8009c920:
      DAT_8013273c = 2;
    }
  }
  else {
LAB_8009c8ac:
    DAT_8013272a = 3;
    DAT_8013273c = 4;
  }
  uVar6 = DAT_800df934;
  DAT_800e1124._1_1_ = 0;
  local_20[0] = 0;
  if (DAT_8013273c == 2) {
    local_20[0] = 0x2cff;
    DAT_80119ea0 = local_20;
    DAT_80119ee5 = 0;
    DAT_80119ee8 = 100;
    DAT_80119eea = 100;
    DAT_800df934 = DAT_800c52d8;
    FUN_80076c84();
    DAT_80132738 = 0xc;
    uVar1 = 0x15ba;
    DAT_80132748 = &DAT_801324ac;
LAB_8009cba4:
    DAT_800df934 = uVar6;
    FUN_800479c8(DAT_800c52d8,&DAT_80132644,uVar1,0);
    puVar4 = &DAT_80132660;
    uVar1 = 0x15bb;
    iVar2 = DAT_800c52d8;
    iVar3 = 62000;
  }
  else {
    if (2 < DAT_8013273c) {
      if (DAT_8013273c != 3) goto LAB_8009cbd8;
      DAT_800e1124._1_1_ = 0xff;
      DAT_800e1124._0_1_ = local_24;
      FUN_8004cd88(1);
      uVar6 = DAT_800df934;
      local_20[0] = 0x2cff;
      DAT_80119ea0 = local_20;
      DAT_80119ee5 = 0;
      DAT_80119ee8 = 100;
      DAT_80119eea = 100;
      DAT_800df934 = DAT_800c52d8 + 0x52c38;
      FUN_80076c84();
      DAT_80132738 = 0x12;
      uVar1 = 0x15b9;
      DAT_80132748 = &DAT_8013253c;
      goto LAB_8009cba4;
    }
    local_20[0] = 0x2bff;
    DAT_80119ea0 = local_20;
    DAT_80119ee5 = 0;
    DAT_80119ee8 = 100;
    DAT_80119eea = 100;
    DAT_800df934 = DAT_800c52d8 + 0x52c38;
    FUN_80076c84();
    DAT_80132738 = 0x1c;
    DAT_80132748 = &DAT_8013235c;
    DAT_800df934 = uVar6;
    FUN_800479c8(DAT_800c52d8,&DAT_80132644,0x15b4,0);
    FUN_800479c8(DAT_800c52d8 + 62000,&DAT_80132660,0x15b5,0);
    FUN_800479c8(DAT_800c52d8 + 0x255a8,&DAT_8013267c,0x15b6,0);
    FUN_800479c8(DAT_800c52d8 + 0x347d8,&DAT_80132698,0x15b7,0);
    iVar2 = 0x43a08;
    puVar4 = &DAT_801326b4;
    uVar1 = 0x15b8;
    iVar3 = DAT_800c52d8;
  }
  FUN_800479c8(iVar2 + iVar3,puVar4,uVar1,0);
LAB_8009cbd8:
  iVar2 = FUN_800479c8(DAT_800c52dc + 0x3b800,&DAT_801326ec,0x15bc,1);
  FUN_800479c8(iVar2 + 7U & 0xfffffff8,&DAT_801326d0,0x15bd,1);
  DAT_80132708 = 0;
  DAT_8013270c = 0;
  DAT_80132710 = 0;
  DAT_80132714 = 0;
  DAT_80132718 = 0;
  DAT_8013271c = 0;
  DAT_80132720 = 0;
  _DAT_80012820 = 0;
  DAT_80132658 = DAT_80132658 + -0x1e00;
  DAT_80132674 = DAT_80132674 + -0x1e00;
  DAT_80132690 = DAT_80132690 + -0x1e00;
  DAT_801326ac = DAT_801326ac + -0x1e00;
  DAT_801326c8 = DAT_801326c8 + -0x1e00;
  return;
}
