/* FUN_800a3bf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a3bf4  body 0x800a3bf4..0x800a455f  size 2412 B
 * body sha256 2482e1d8a07b3f709e7f8ae05b13083d77ff34c506ab5abdaa26d8776316a896
 * provider record sha256 67b2529b9f5308bcfc5f7738a75e5f34563df5cf54b2e7810cb3c48148792092
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a3bf4(char *param_1,undefined4 param_2,char param_3)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  ushort uVar6;
  short *psVar5;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  short unaff_s3;
  uint unaff_s4;
  short sVar11;
  undefined4 uVar12;
  double in_f0_1;
  float fVar14;
  double dVar13;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  int local_3c;
  ushort uStack_36;
  undefined4 local_34;
  char local_30 [8];
  
  sVar11 = (short)unaff_s4;
  _DAT_80143fe0 = _DAT_80143fe0 + 0x50;
  puVar7 = (ushort *)(_DAT_80143f50 + (uint)*_DAT_80143f54 * 0xa10);
  puVar7 = puVar7 + (uint)*puVar7 * 0x28 + 8;
  _DAT_80143fe4 = FUN_80135cb0(_DAT_80143fe4);
  local_40 = (uint)*(ushort *)(param_1 + 4) * 0xc0 + 0xfff >> 0xc;
  FUN_800a6258(*(undefined8 *)(param_1 + 8));
  iVar10 = local_40 + 6;
  if (in_f0_1 < 2147483648.0) {
    local_48 = (uint)in_f0_1;
  }
  else {
    in_f0_1 = in_f0_1 - 2147483648.0;
    local_48 = (int)in_f0_1 | 0x80000000;
  }
  uVar12 = (undefined4)((ulonglong)in_f0_1 >> 0x20);
  local_30[0] = '\x02';
  uVar2 = *(uint *)(param_1 + 0x38);
  uVar8 = *(int *)(param_1 + 0x34) + uVar2;
  if ((uVar2 == 0) ||
     (((param_1[1] == '\0' && (*(int *)(param_1 + 0x3c) != 0)) || (uVar8 < local_48)))) {
    uVar6 = 0;
    if (local_48 + iVar10 < *(uint *)(param_1 + 0x30)) goto LAB_800a3dfc;
    iVar10 = -2;
    local_3c = 0;
    local_30[0] = '\0';
    local_40 = (*(int *)(param_1 + 0x30) - local_48) + 0x20;
  }
  else if (uVar8 < local_48 + iVar10) {
    uVar9 = *(uint *)(param_1 + 0x34);
    local_40 = uVar8 - local_48;
    if (uVar9 < local_48) {
      uVar8 = iVar10 - local_40;
      if ((uVar2 < uVar8) || (uVar6 = 0, local_48 - uVar9 <= uVar8)) {
        uVar6 = (short)local_48 - (short)uVar9;
        local_40 = *(uint *)(param_1 + 0x38);
        iVar10 = 0;
        local_3c = 0;
        local_48 = uVar9;
      }
      else {
        iVar10 = 0;
        local_44 = *(uint *)(param_1 + 0x34);
        local_3c = uVar8 - 6;
      }
    }
    else {
      local_3c = 0;
      local_40 = (*(int *)(param_1 + 0x34) - local_48) + *(int *)(param_1 + 0x38);
      uVar6 = 0;
      iVar10 = *(int *)(param_1 + 0x34) - local_48;
    }
  }
  else {
LAB_800a3dfc:
    uVar6 = 0;
    iVar10 = -1;
    local_3c = 0;
  }
  iVar3 = local_40 + 6;
  if (local_3c != 0) {
    local_34 = local_3c + 6;
  }
  uStack_36 = (ushort)iVar3;
  if ((*(ushort *)(param_1 + 2) & 1) == 0) {
    if (param_1[0x5d] == '\0') {
      if (local_3c == 0) {
        puVar7[0x18] = 0;
        puVar7[0x19] = 0;
        puVar7[0x21] = 0;
      }
      else {
        uVar2 = local_44 & 3;
        sVar11 = (short)uVar2;
        *(uint *)(puVar7 + 0x18) = *(int *)(param_1 + 0x2c) + (local_44 & 0xfffc) * 2;
        puVar7[0x1d] = 0;
        puVar7[0x1c] = (ushort)((uVar2 + local_34 + 3 & 0xfffc) << 1);
        *(char *)((int)puVar7 + 0x3f) = (char)uVar2;
        puVar7[0x21] = local_34._2_2_;
      }
      *(uint *)(puVar7 + 0x12) = *(int *)(param_1 + 0x2c) + (local_48 & 0xfffc) * 2;
      puVar7[0x17] = 0;
      puVar7[0x16] = (ushort)(((local_48 & 3) + iVar3 + 3 & 0xfffc) << 1);
      goto LAB_800a41d0;
    }
    if (param_1[0x5d] != '\x03') goto LAB_800a41e4;
    if (local_3c == 0) {
      puVar7[0x18] = 0;
      puVar7[0x19] = 0;
      *(undefined1 *)((int)puVar7 + 0x3d) = 0;
    }
    else {
      unaff_s4 = local_44 & 0x1f;
      *(uint *)(puVar7 + 0x18) = *(int *)(param_1 + 0x2c) + (local_44 >> 6) * 0x28 + 0x100;
      puVar7[0x1d] = 0;
      *(char *)((int)puVar7 + 0x3f) = (char)(local_44 & 0x3f);
      puVar7[0x1c] = (short)((local_34 + unaff_s4 + 0x1f >> 5) + ((local_44 & 0x3f) >> 5) + 1 >> 1)
                     * 0x28;
      *(char *)((int)puVar7 + 0x3d) = (char)(unaff_s4 + local_34 + 0x1f >> 5);
    }
    sVar11 = (short)unaff_s4;
    *(uint *)(puVar7 + 0x12) = *(int *)(param_1 + 0x2c) + (local_48 >> 6) * 0x28 + 0x100;
    puVar7[0x17] = 0;
    puVar7[0x16] = (short)((iVar3 + (local_48 & 0x1f) + 0x1f >> 5) + ((local_48 & 0x3f) >> 5) + 1 >>
                          1) * 0x28;
    *(undefined4 *)(puVar7 + 0x20) = *(undefined4 *)(param_1 + 0x2c);
  }
  else {
    if (param_1[0x5d] == '\0') {
      if (local_3c == 0) {
        puVar7[0x18] = 0;
        puVar7[0x19] = 0;
        puVar7[0x21] = 0;
      }
      else {
        uVar2 = local_44 & 3;
        sVar11 = (short)uVar2;
        FUN_800a3660(puVar7 + 0x18,*(int *)(param_1 + 0x2c) + (local_44 & 0xfffc) * 2,
                     (uVar2 + local_34 + 3 & 0xfffc) << 1);
        *(char *)((int)puVar7 + 0x3f) = (char)uVar2;
        puVar7[0x21] = local_34._2_2_;
      }
      FUN_800a3660(puVar7 + 0x12,*(int *)(param_1 + 0x2c) + (local_48 & 0xfffc) * 2,
                   ((local_48 & 3) + iVar3 + 3 & 0xfffc) << 1);
LAB_800a41d0:
      unaff_s3 = (short)(local_48 & 3);
      *(undefined1 *)(puVar7 + 0x1e) = 0;
      *(char *)(puVar7 + 0x1f) = (char)(local_48 & 3);
      puVar7[0x20] = uStack_36;
      goto LAB_800a41e4;
    }
    if (param_1[0x5d] != '\x03') goto LAB_800a41e4;
    if (local_3c == 0) {
      puVar7[0x18] = 0;
      puVar7[0x19] = 0;
      *(undefined1 *)((int)puVar7 + 0x3d) = 0;
    }
    else {
      unaff_s4 = local_44 & 0x1f;
      FUN_800a3660(puVar7 + 0x18,*(int *)(param_1 + 0x2c) + (local_44 >> 6) * 0x28 + 0x100,
                   ((local_34 + unaff_s4 + 0x1f >> 5) + ((local_44 & 0x3f) >> 5) + 1 >> 1) * 0x28,
                   *(int *)(param_1 + 0x2c) + 0x100);
      *(char *)((int)puVar7 + 0x3f) = (char)(local_44 & 0x3f);
      *(char *)((int)puVar7 + 0x3d) = (char)(unaff_s4 + local_34 + 0x1f >> 5);
    }
    sVar11 = (short)unaff_s4;
    FUN_800a3660(puVar7 + 0x12,*(int *)(param_1 + 0x2c) + (local_48 >> 6) * 0x28 + 0x100,
                 ((iVar3 + (local_48 & 0x1f) + 0x1f >> 5) + ((local_48 & 0x3f) >> 5) + 1 >> 1) *
                 0x28,*(int *)(param_1 + 0x2c) + 0x100);
    uVar4 = FUN_800a3374(*(undefined4 *)(param_1 + 0x2c));
    *(undefined4 *)(puVar7 + 0x20) = uVar4;
  }
  *(byte *)(puVar7 + 0x1f) = (byte)local_48 & 0x3f;
  unaff_s3 = (short)(local_48 & 0x1f);
  *(char *)(puVar7 + 0x1e) = (char)((local_48 & 0x1f) + iVar3 + 0x1f >> 5);
LAB_800a41e4:
  puVar7[0x27] = uVar6;
  if (iVar10 == -1) {
    puVar7[0x24] = 0x4000;
  }
  else {
    if (iVar10 == -2) {
      puVar7[0x24] = unaff_s3 + local_40._2_2_;
      uVar6 = (unaff_s3 + local_40._2_2_) - 0x20;
    }
    else {
      puVar7[0x24] = unaff_s3 + local_40._2_2_;
      if (*(int *)(puVar7 + 0x18) == 0) {
        uVar6 = unaff_s3 + (short)iVar10;
      }
      else {
        uVar6 = sVar11 + (short)iVar10 | 0x8000;
      }
    }
    puVar7[0x25] = uVar6;
  }
  param_1[0x60] = param_3;
  FUN_800a2f08(param_1,0xc0,local_30);
  if (*param_1 == '\x01') {
    *(short *)(param_1 + 0x18) =
         (short)(int)((float)(int)*(short *)(param_1 + 0x40) * *(float *)(param_1 + 0x4c));
    *(int *)puVar7 =
         (int)((float)(int)*(short *)(param_1 + 0x40) * *(float *)(param_1 + 0x4c)) << 0x10;
    *(short *)(param_1 + 0x1a) =
         (short)(int)((float)(int)*(short *)(param_1 + 0x42) * *(float *)(param_1 + 0x4c));
    *(int *)(puVar7 + 2) =
         (int)((float)(int)*(short *)(param_1 + 0x42) * *(float *)(param_1 + 0x4c)) << 0x10;
    *(short *)(param_1 + 0x1c) =
         (short)(int)((float)(int)*(short *)(param_1 + 0x44) * *(float *)(param_1 + 0x4c));
    *(int *)(puVar7 + 4) =
         (int)((float)(int)*(short *)(param_1 + 0x44) * *(float *)(param_1 + 0x4c)) << 0x10;
    fVar14 = (float)(int)*(short *)(param_1 + 0x46) * *(float *)(param_1 + 0x4c);
    *(short *)(param_1 + 0x1e) = (short)(int)fVar14;
    *(int *)(puVar7 + 6) = (int)fVar14 << 0x10;
    puVar7[0xe] = 0;
    puVar7[0xf] = 0;
    puVar7[0xc] = 0;
    puVar7[0xd] = 0;
    puVar7[10] = 0;
    puVar7[0xb] = 0;
    puVar7[8] = 0;
    puVar7[9] = 0;
  }
  else {
    *(int *)puVar7 = (int)*(short *)(param_1 + 0x18) << 0x10;
    *(int *)(puVar7 + 2) = (int)*(short *)(param_1 + 0x1a) << 0x10;
    *(int *)(puVar7 + 4) = (int)*(short *)(param_1 + 0x1c) << 0x10;
    *(int *)(puVar7 + 6) = (int)*(short *)(param_1 + 0x1e) << 0x10;
    *(short *)(param_1 + 0x18) =
         (short)(int)((float)(int)*(short *)(param_1 + 0x40) * *(float *)(param_1 + 0x4c));
    iVar3 = (int)((float)(int)*(short *)(param_1 + 0x40) * *(float *)(param_1 + 0x4c)) * 0x10000 -
            *(int *)puVar7;
    iVar10 = iVar3 >> 0x1f;
    *(int *)(puVar7 + 8) = (iVar3 / 6 + iVar10 >> 5) - iVar10;
    *(short *)(param_1 + 0x1a) =
         (short)(int)((float)(int)*(short *)(param_1 + 0x42) * *(float *)(param_1 + 0x4c));
    iVar3 = (int)((float)(int)*(short *)(param_1 + 0x42) * *(float *)(param_1 + 0x4c)) * 0x10000 -
            *(int *)(puVar7 + 2);
    iVar10 = iVar3 >> 0x1f;
    *(int *)(puVar7 + 10) = (iVar3 / 6 + iVar10 >> 5) - iVar10;
    *(short *)(param_1 + 0x1c) =
         (short)(int)((float)(int)*(short *)(param_1 + 0x44) * *(float *)(param_1 + 0x4c));
    iVar3 = (int)((float)(int)*(short *)(param_1 + 0x44) * *(float *)(param_1 + 0x4c)) * 0x10000 -
            *(int *)(puVar7 + 4);
    iVar10 = iVar3 >> 0x1f;
    *(int *)(puVar7 + 0xc) = (iVar3 / 6 + iVar10 >> 5) - iVar10;
    fVar14 = (float)(int)*(short *)(param_1 + 0x46) * *(float *)(param_1 + 0x4c);
    *(short *)(param_1 + 0x1e) = (short)(int)fVar14;
    iVar3 = (int)fVar14 * 0x10000 - *(int *)(puVar7 + 6);
    iVar10 = iVar3 >> 0x1f;
    *(int *)(puVar7 + 0xe) = (iVar3 / 6 + iVar10 >> 5) - iVar10;
  }
  dVar13 = (double)CONCAT44(uVar12,fVar14);
  puVar7[0x11] = *(ushort *)(param_1 + 4);
  FUN_800a6258(*(undefined8 *)(param_1 + 8));
  dVar13 = (*(double *)(param_1 + 8) - dVar13) * 65536.0;
  if (dVar13 < 2147483648.0) {
    uVar6 = (ushort)(int)dVar13;
    puVar7[0x10] = uVar6;
  }
  else {
    uVar6 = (ushort)(int)(dVar13 - 2147483648.0);
    puVar7[0x10] = uVar6;
  }
  sVar11 = *(short *)(param_1 + 4);
  puVar7[0x22] = 0;
  puVar1 = _DAT_80143f54;
  puVar7[0x23] = 0;
  puVar7[0x26] = uVar6 + sVar11 * 0x10 * uStack_36;
  psVar5 = (short *)((uint)*puVar1 * 0xa10 + _DAT_80143f50);
  *psVar5 = *psVar5 + 1;
  FUN_800a3094(param_1,0xc0);
  *param_1 = local_30[0];
  return;
}
