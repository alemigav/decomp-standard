/* FUN_8005fce0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005fce0  body 0x8005fce0..0x8006087b  size 2972 B
 * body sha256 0a0c9c302b074bd878d6b50baa2357120d77fe5cf26deb8514c4926e09afde67
 * provider record sha256 68f9a395ac767bee062d21bb76cddb7aa00a684999716cbc4bc20ce7f63301e6
 * callees 17 direct (17 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005fce0(int param_1)

{
  byte bVar1;
  int iVar2;
  ushort uVar4;
  uint uVar3;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  ushort *puVar9;
  uint *puVar10;
  int iVar11;
  ushort local_98;
  ushort local_96;
  ushort local_94;
  short local_90;
  short local_8e;
  short local_8c;
  undefined1 auStack_88 [32];
  short local_68;
  short local_66;
  short local_64;
  undefined1 auStack_58 [2];
  short local_56;
  short local_54;
  undefined1 auStack_50 [2];
  ushort local_4e;
  ushort local_4c;
  undefined4 local_48;
  undefined4 local_44;
  ushort local_40 [2];
  int local_3c;
  char local_38;
  short *local_34;
  ushort *local_30;
  
  local_34 = &local_90;
  local_30 = local_40;
  local_3c = 6;
  local_38 = '\x01';
  local_48 = 0xfe0c0000;
  local_44 = 0x1770019;
  iVar2 = *(int *)(param_1 + 0x234);
  puVar10 = (uint *)(iVar2 + 0x1d60);
  puVar9 = (ushort *)(iVar2 + 0x1e92);
  iVar11 = iVar2 + 0x1dac;
  iVar2 = iVar2 + 0x1d98;
  do {
    switch(*(undefined1 *)(puVar9 + -1)) {
    case 0:
      *puVar10 = *puVar10 | 0x8040;
      *(undefined1 *)(puVar9 + -1) = 1;
      *(uint *)(puVar9 + 0x23) = *(uint *)(puVar9 + 0x23) | 0x8000;
      *puVar10 = *puVar10 | 0x400;
      puVar9[-6] = 0x2000;
      puVar9[0xb6] = 0x2000;
      puVar9[-7] = 0x1000;
      puVar9[-5] = 0x1000;
      puVar9[0xb5] = 0x1000;
      puVar9[0xb7] = 0x1000;
      puVar9[-0xb] = 10;
      *(undefined1 *)((int)puVar9 + -0x21) = 0;
      *(undefined1 *)(puVar9 + -0x10) = 0;
      *(uint *)(puVar9 + 0x23) = *(uint *)(puVar9 + 0x23) | 0x400;
      local_98 = 0;
      uVar4 = FUN_80033604();
      local_94 = (uVar4 & 1) * -0x28 + 0x14;
      if (*(int *)(puVar9 + -0x87) == -100) {
        local_98 = 100;
        uVar4 = FUN_80033604();
        local_94 = (uVar4 & 1) * -0x3c + 0x1e;
      }
      if (*(int *)(puVar9 + -0x87) == 100) {
        local_98 = 0xff9c;
        uVar4 = FUN_80033604(&local_98);
        local_94 = (uVar4 & 1) * -0x3c + 0x1e;
      }
      local_96 = 0;
      FUN_80040e58(&local_98,auStack_88);
      FUN_80041fe0(iVar2,auStack_88);
      FUN_80069f1c(iVar11,200,0x2000,0);
      if (DAT_8011270c != 0) {
        *(undefined1 *)(puVar9 + -1) = 2;
        return;
      }
      local_38 = '\0';
    case 1:
      local_98 = 0;
      local_96 = 800;
      local_94 = 0;
      FUN_8004276c(iVar2,&local_98,local_34);
      *(int *)(puVar9 + -0x73) = *(int *)(puVar9 + -0x73) + (int)local_90;
      *(int *)(puVar9 + -0x71) = *(int *)(puVar9 + -0x71) + (int)local_8e;
      *(int *)(puVar9 + -0x6f) = *(int *)(puVar9 + -0x6f) + (int)local_8c;
      if (local_38 == '\0') {
        *(int *)(puVar9 + -0x73) = *(int *)(puVar9 + -0x73) - (int)local_90;
        *(int *)(puVar9 + -0x71) = *(int *)(puVar9 + -0x71) - (int)local_8e;
        *(int *)(puVar9 + -0x6f) = *(int *)(puVar9 + -0x6f) - (int)local_8c;
      }
      FUN_800608c8(local_34,auStack_50);
      *puVar9 = local_4e;
      if (*(int *)(puVar9 + -0x87) == 0) {
        uVar7 = 10000;
      }
      else {
        uVar7 = 3000;
      }
      iVar6 = FUN_8005fb54(iVar11,(int)(short)local_4e,uVar7,800);
      uVar3 = FUN_8006114c(iVar6,iVar2,&DAT_801105f8);
      uVar3 = uVar3 & 0xffff;
      iVar8 = *(int *)(iVar6 + 0x234) + uVar3 * 0x178;
      local_68 = (short)(*(int *)(iVar8 + 0x4c) - *(int *)(puVar9 + -0x73) >> 3);
      local_66 = (short)(*(int *)(iVar8 + 0x50) - *(int *)(puVar9 + -0x71) >> 3);
      local_64 = (short)(*(int *)(iVar8 + 0x54) - *(int *)(puVar9 + -0x6f) >> 3);
      FUN_800608c8(&local_68,auStack_58);
      if ((iVar6 != param_1) && (puVar9[-0xb] != 0)) {
        FUN_8006087c((int)local_56,(int)(short)local_4e,0x18,local_30);
        local_4e = local_40[0];
        FUN_8006087c((int)local_54,(int)(short)local_4c,0x40,local_30);
        local_4c = local_40[0];
        FUN_80040e58(auStack_50,iVar2);
        puVar9[-0xb] = puVar9[-0xb] - 1;
      }
      FUN_80069f1c(iVar11,100,0x2000,0);
      if (DAT_8011270c != 0) {
        *(undefined1 *)(puVar9 + -1) = 2;
      }
      if (*(int *)(puVar9 + -0x71) < DAT_80112708) {
        *(undefined1 *)(puVar9 + -1) = 2;
      }
      if (60000 < *(int *)(puVar9 + -0x73) + 30000U) {
        *(undefined1 *)(puVar9 + -1) = 2;
        *(undefined1 *)((int)puVar9 + -0x21) = 1;
      }
      if (60000 < *(int *)(puVar9 + -0x71) + 30000U) {
        *(undefined1 *)(puVar9 + -1) = 2;
        *(undefined1 *)((int)puVar9 + -0x21) = 1;
      }
      if (60000 < *(int *)(puVar9 + -0x6f) + 30000U) {
        *(undefined1 *)(puVar9 + -1) = 2;
        *(undefined1 *)((int)puVar9 + -0x21) = 1;
      }
      iVar6 = FUN_800609e0(iVar11,(int)(short)puVar9[-0xe],&local_48,0xc);
      *(int *)(puVar9 + 1) = iVar6;
      if (iVar6 != 0) {
        uVar3 = FUN_8006114c(iVar6,iVar2,&DAT_801105f8);
        uVar3 = uVar3 & 0xffff;
      }
      uVar4 = FUN_80074d64(*(undefined4 *)(puVar9 + -0x73),*(undefined4 *)(puVar9 + -0x6f));
      iVar6 = (int)(short)uVar4;
      if (iVar6 != 0) {
        if (iVar6 < *(int *)(puVar9 + -0x71)) {
          uVar5 = FUN_80033604();
          FUN_80037780((uVar5 & 0xff) * 2 + 0x418 | 0x1a000000,
                       (int)((local_4e + 0x800) * 0x10000) >> 0x10,iVar2,0);
          local_96 = 200;
          uVar5 = FUN_80033604();
          FUN_80037780((uVar5 & 0xff) * 2 + 0x418 | 0x1a000000,
                       (int)((local_4e + 0x800) * 0x10000) >> 0x10,iVar2,&local_98);
          local_96 = 400;
          uVar5 = FUN_80033604();
          FUN_80037780((uVar5 & 0xff) * 2 + 0x418 | 0x1a000000,
                       (int)((local_4e + 0x800) * 0x10000) >> 0x10,iVar2,&local_98);
          local_96 = 600;
          uVar5 = FUN_80033604();
          FUN_80037780((uVar5 & 0xff) * 2 + 0x418 | 0x1a000000,
                       (int)((local_4e + 0x800) * 0x10000) >> 0x10,iVar2,&local_98);
        }
        if ((*(char *)(puVar9 + -0x10) == '\0') && (iVar6 < *(int *)(puVar9 + -0x71))) {
          local_98 = puVar9[-0x72];
          *(undefined1 *)(puVar9 + -0x10) = 1;
          local_94 = puVar9[-0x6e];
          local_96 = uVar4;
          uVar5 = FUN_80033604();
          FUN_80037780((uVar5 & 0xff) * 2 + 0x418 | 0x1a050000,0,&DAT_800e9028,&local_98);
        }
      }
      if (*(int *)(puVar9 + 1) != 0) {
        *(undefined1 *)(puVar9 + -1) = 5;
        *(char *)((int)puVar9 + -1) = (char)uVar3;
        *(uint **)(*(int *)(puVar9 + 1) + 0x29c) = puVar10;
        if (*(char *)(*(int *)(puVar9 + 1) + 8) == '!') {
          *(short *)(*(int *)(puVar9 + 1) + 0x1e0) = local_90;
          *(short *)(*(int *)(puVar9 + 1) + 0x1e2) = local_8e;
          *(short *)(*(int *)(puVar9 + 1) + 0x1e4) = local_8c;
        }
      }
      break;
    case 2:
      *puVar10 = *puVar10 & 0xfffffbff;
      *(uint *)(puVar9 + 0x23) = *(uint *)(puVar9 + 0x23) & 0xfffffbff;
      if (*(char *)((int)puVar9 + -0x21) == '\0') {
        FUN_80077adc(0x10a0001,iVar11);
      }
      puVar9[-0xb] = 0x14;
      *(undefined1 *)(puVar9 + -1) = 3;
      *(undefined1 *)((int)puVar9 + -0x21) = 0xff;
      puVar9[0x23] = 0;
      puVar9[0x24] = 0;
      puVar9[-10] = puVar9[-0x70];
      local_98 = 0;
      local_96 = 400;
      local_94 = 0;
      FUN_8004276c(iVar2,&local_98,&local_90);
      *(int *)(puVar9 + -0x73) = *(int *)(puVar9 + -0x73) + (int)local_90;
      *(int *)(puVar9 + -0x71) = *(int *)(puVar9 + -0x71) + (int)local_8e;
      *(int *)(puVar9 + -0x6f) = *(int *)(puVar9 + -0x6f) + (int)local_8c;
    case 3:
      local_98 = 0;
      local_96 = puVar9[-0xb] * *(char *)((int)puVar9 + -0x21) * 8;
      local_94 = puVar9[-0xb] * *(char *)((int)puVar9 + -0x21) * 8;
      FUN_80040e58(&local_98,auStack_88);
      FUN_8004226c(iVar2,auStack_88,iVar2);
      uVar4 = puVar9[-0xb];
      puVar9[-0xb] = uVar4 - 1;
      *(char *)((int)puVar9 + -0x21) = -*(char *)((int)puVar9 + -0x21);
      if ((ushort)(uVar4 - 1) == 0xffff) {
        *(undefined1 *)(puVar9 + -1) = 4;
      }
      if ((_DAT_800e8ca8 == 0x40009) && (iVar6 = FUN_80032b10(iVar11,&DAT_801110f8), iVar6 == 0)) {
        *(int *)(puVar9 + -0x71) = *(int *)(puVar9 + -0x71) + -0xb4;
      }
      break;
    case 4:
      *puVar10 = 0;
      puVar9[0x23] = 0;
      puVar9[0x24] = 0;
      *(undefined1 *)(puVar9 + -1) = 0xff;
      iVar6 = *(int *)(param_1 + 0x234);
      *(int *)(puVar9 + -0x67) = iVar6 + 0x1060;
      *(int *)(puVar9 + -3) = iVar6 + 0x1028;
      *puVar10 = *puVar10 | 0x40;
      puVar9[-0xffffffff0000008b] = 0;
      puVar9[-0xffffffff0000008a] = 200;
      puVar9[-0xffffffff00000089] = 0;
      puVar9[-0xffffffff00000088] = 0x390;
      puVar9[-0xffffffff00000087] = 0;
      puVar9[-0xffffffff00000086] = 0;
      break;
    case 5:
      *puVar10 = *puVar10 & 0xfffffbff;
      puVar9[-0xb] = 0x4b;
      *(uint *)(puVar9 + 0x23) = *(uint *)(puVar9 + 0x23) & 0xfffffbff;
      if ((*(char *)(*(int *)(puVar9 + 1) + 8) == '6') ||
         (*(char *)(*(int *)(puVar9 + 1) + 8) == '#')) {
        puVar9[-0xb] = 10;
      }
      *(undefined1 *)(puVar9 + -1) = 6;
      *(undefined1 *)((int)puVar9 + -0x21) = 0xff;
      puVar9[-10] = puVar9[-0x70];
      iVar6 = *(int *)(*(int *)(puVar9 + 1) + 0x234) + (uint)*(byte *)((int)puVar9 + -1) * 0x178;
      local_68 = *(short *)(iVar6 + 0x4e) - puVar9[-0x72];
      local_66 = *(short *)(iVar6 + 0x52) - puVar9[-0x70];
      local_64 = *(short *)(iVar6 + 0x56) - puVar9[-0x6e];
      FUN_800608c8(&local_68,auStack_58);
      FUN_80040e58(auStack_58,iVar2);
      iVar6 = FUN_80040bb4((int)local_68 * (int)local_68 + (int)local_64 * (int)local_64);
      uVar3 = FUN_80040bb4(iVar6 * iVar6 + (int)local_66 * (int)local_66);
      local_96 = (short)(uVar3 >> 2) * 3;
      local_98 = 0;
      local_94 = 0;
      FUN_8004276c(iVar2,&local_98,&local_90);
      *(int *)(puVar9 + -0x73) = *(int *)(puVar9 + -0x73) + (int)local_90;
      *(int *)(puVar9 + -0x71) = *(int *)(puVar9 + -0x71) + (int)local_8e;
      *(int *)(puVar9 + -0x6f) = *(int *)(puVar9 + -0x6f) + (int)local_8c;
      FUN_80077adc(0x10f0001,iVar11);
      iVar8 = *(int *)(*(int *)(puVar9 + 1) + 0x234) + (uint)*(byte *)((int)puVar9 + -1) * 0x178;
      iVar6 = iVar8 + 0x38;
      FUN_80049ff8(iVar6,iVar2,puVar10 + 2);
      *(int *)(puVar9 + -0x67) = iVar6;
      *(int *)(puVar9 + -3) = iVar8;
      *puVar10 = *puVar10 & 0xffffffbf;
      if ((**(uint **)(puVar9 + 1) & 0x10000) == 0) {
        local_98 = puVar9[-0x8a];
        local_96 = puVar9[-0x88];
        local_94 = puVar9[-0x86];
        FUN_80037780((**(uint **)(puVar9 + 1) >> 0x13 & 0x18) << 0x10 | 0x1bb8,
                     (int)((*puVar9 - 0x800) * 0x10000) >> 0x10,
                     (*(uint **)(puVar9 + 1))[0x8d] + (uint)*(byte *)((int)puVar9 + -1) * 0x178 +
                     0x38,&local_98);
      }
    case 6:
      uVar4 = puVar9[-0xb];
      puVar9[-0xb] = uVar4 - 1;
      if ((ushort)(uVar4 - 1) == 0xffff) {
        *(undefined1 *)(puVar9 + -1) = 4;
      }
      if (((puVar9[-0xb] & 3) == 0) && ((**(uint **)(puVar9 + 1) & 0x10000) == 0)) {
        local_98 = puVar9[-0x8a];
        bVar1 = *(byte *)((int)puVar9 + -1);
        uVar5 = (*(uint **)(puVar9 + 1))[0x8d];
        local_96 = puVar9[-0x88];
        local_94 = puVar9[-0x86];
        uVar3 = FUN_80033604();
        FUN_80037780((**(uint **)(puVar9 + 1) >> 0x13 & 0x18) << 0x10 | ((uVar3 & 0xff) + 0x200) * 2
                     ,(int)((*puVar9 - 0x800) * 0x10000) >> 0x10,uVar5 + (uint)bVar1 * 0x178 + 0x38,
                     &local_98);
      }
    }
    puVar9 = puVar9 + 0x178;
    iVar11 = iVar11 + 0x2f0;
    iVar2 = iVar2 + 0x2f0;
    puVar10 = puVar10 + 0xbc;
    local_3c = local_3c + -1;
    if (local_3c == 0) {
      return;
    }
  } while( true );
}
