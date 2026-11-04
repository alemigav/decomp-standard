/* FUN_80077f30
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80077f30  body 0x80077f30..0x8007849b  size 1388 B
 * body sha256 24e84e9a651f9e62cbb4f0beebc79958eae7aabdcd22fb9946a3f5882be99c3a
 * provider record sha256 5b26e2f282fa621df98d4a31ac4e4f61b15252faf46a9aff0ed15abd9640dd03
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80077f30(short param_1,short param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  ushort uVar11;
  int iVar12;
  undefined2 local_38;
  short local_36;
  undefined2 local_34;
  ushort local_2a;
  
  if (*(char *)(param_3 + 8) == '\r') {
    iVar12 = 4;
    uVar9 = (uint)(param_2 != 4);
    local_2a = 0xb;
    iVar5 = DAT_80119edc;
  }
  else {
    iVar12 = 2;
    local_2a = FUN_80074e84(*(undefined4 *)(param_3 + 0x28),*(undefined4 *)(param_3 + 0x30),
                            *(undefined1 *)(param_3 + 0x1a2));
    local_2a = local_2a & 0xff;
    iVar5 = DAT_80119ed4;
    if (*(byte *)(param_3 + 8) < 0x10) {
      uVar9 = (uint)(param_2 != 4);
    }
    else {
      uVar9 = 3;
      if (param_2 == 4) {
        uVar9 = 2;
      }
    }
  }
  iVar7 = DAT_80119ed4;
  if (*(short *)(param_3 + 0x1a8) != 0) {
    iVar8 = *(int *)(param_3 + 0x234);
    local_2a = 0x1a;
    local_36 = *(short *)(param_3 + 0x1a8) - *(short *)(iVar8 + 0x1ca);
    iVar12 = 2;
    if (param_2 == 4) {
      local_34 = 0xff60;
    }
    else {
      local_34 = 0xa0;
    }
    iVar5 = iVar7;
    if (*(byte *)(param_3 + 8) == 0xf) {
      if (local_36 < 500) {
        if (param_1 == 0) {
          FUN_80052d10(1,0x82,100,0);
          FUN_80052d10(9,0x55,10,1);
        }
        if (param_1 == 1) {
          FUN_80052d10(3,0x32,100,0);
          FUN_80052d10(5,0x55,0,3);
        }
      }
      local_36 = local_36 + 100;
      if (param_1 == 0) {
        iVar7 = iVar8 + 0x1b0;
        local_38 = 100;
        FUN_80037780(0x1a000e00,(int)(short)DAT_800e1196,iVar7,&local_38);
        local_38 = 0;
        FUN_80037780(0x1a000c00,(int)((DAT_800e1196 + 0x400) * 0x10000) >> 0x10,iVar7,&local_38);
        FUN_80037780(0x1a000c00,(int)((DAT_800e1196 + 0xc00) * 0x10000) >> 0x10,iVar7,&local_38);
      }
      if (param_1 != 1) goto LAB_8007835c;
      local_38 = 300;
      FUN_80037780(0x1a001200,(int)(short)DAT_800e1196,iVar8 + 0x1b0,&local_38);
      local_38 = 0;
      FUN_80037780(0x1a000e00,(int)((DAT_800e1196 + 0x400) * 0x10000) >> 0x10,iVar8 + 0x1b0,
                   &local_38);
      uVar4 = 0x1a000e00;
    }
    else {
      if ((local_36 < 0x4b0) && (*(byte *)(param_3 + 8) < 0x10)) {
        if (param_1 == 0) {
          FUN_80052d10(1,0x82,100,0);
          FUN_80052d10(9,0x55,10,1);
        }
        if (param_1 == 1) {
          FUN_80052d10(3,0x32,100,0);
          FUN_80052d10(5,0x55,10,3);
        }
      }
      if (param_1 == 0) {
        iVar7 = iVar8 + 0x1b0;
        local_38 = 200;
        FUN_80037780(0x1a000e00,(int)(short)DAT_800e1196,iVar7,&local_38);
        local_38 = 0;
        FUN_80037780(0x1a000c00,(int)((DAT_800e1196 + 0x400) * 0x10000) >> 0x10,iVar7,&local_38);
        FUN_80037780(0x1a000c00,(int)((DAT_800e1196 + 0xc00) * 0x10000) >> 0x10,iVar7,&local_38);
      }
      if (param_1 != 1) goto LAB_8007835c;
      local_38 = 600;
      FUN_80037780(0x1a001600,(int)(short)DAT_800e1196,iVar8 + 0x1b0,&local_38);
      local_38 = 0;
      FUN_80037780(0x1a001100,(int)((DAT_800e1196 + 0x400) * 0x10000) >> 0x10,iVar8 + 0x1b0,
                   &local_38);
      uVar4 = 0x1a001100;
    }
    FUN_80037780(uVar4,(int)((DAT_800e1196 + 0xc00) * 0x10000) >> 0x10,iVar8 + 0x1b0,&local_38);
  }
LAB_8007835c:
  if (*(int *)(param_3 + 0x280) == 0) {
    uVar11 = param_1 + (local_2a & 0x7f);
  }
  else {
    uVar11 = 6;
  }
  piVar10 = (int *)(iVar5 + (uint)uVar11 * 4);
  if ((*piVar10 != -1) && ((&DAT_80119ea8)[iVar12] != -1)) {
    bVar6 = (*(byte *)((int)piVar10 + 2) & 0xf) - 1;
    cVar3 = FUN_800787dc(uVar9,bVar6);
    if (cVar3 != '\0') {
      uVar9 = 0x17;
    }
    bVar1 = *(byte *)((int)piVar10 + 1);
    bVar2 = *(byte *)((int)piVar10 + 2);
    (&DAT_80119efc)[uVar9 * 2] = bVar6 & 7;
    (&DAT_80119efd)[uVar9 * 2] = (char)uVar9;
    iVar5 = uVar9 * 0x24;
    if (DAT_8011a28e == '\0') {
      *(undefined2 *)(&DAT_80119f4c + iVar5) = 0;
    }
    else {
      *(undefined2 *)(&DAT_80119f4c + iVar5) = 1;
    }
    (&DAT_80119f2d)[iVar5] = (char)uVar11;
    (&DAT_80119f2c)[iVar5] = 1;
    *(short *)(&DAT_80119f30 + iVar5) = (short)iVar12;
    *(ushort *)(&DAT_80119f32 + iVar5) = bVar1 & 0x7f;
    *(ushort *)(&DAT_80119f34 + iVar5) = (ushort)(bVar2 >> 4);
    *(float *)(&DAT_80119f40 + iVar5) = (float)*(int *)(param_3 + 0x28);
    *(float *)(&DAT_80119f44 + iVar5) = (float)*(int *)(param_3 + 0x2c);
    *(float *)(&DAT_80119f48 + iVar5) = (float)*(int *)(param_3 + 0x30);
    *(undefined2 *)(&DAT_80119f3e + iVar5) = 1;
  }
  return;
}
