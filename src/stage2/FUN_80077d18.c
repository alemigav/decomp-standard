/* FUN_80077d18
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80077d18  body 0x80077d18..0x80077f2f  size 536 B
 * body sha256 60b38776f51e4a170acbb2dcf34e9ffb3fb20e589ebe1cfe03008b3bf99340ec
 * provider record sha256 6614ceac306bf3c83a0404d748b9a33c01d35e58523ac2e870c562473df1a3d0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80077d18(byte param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  undefined *puVar9;
  byte *pbVar10;
  uint uVar11;
  ushort uVar12;
  
  if ((*param_2 & 0x2000) != 0) {
    param_1 = param_1 + 0x10;
  }
  uVar12 = 3;
  if (((DAT_80119ed8 != 0) &&
      (pbVar10 = (byte *)(DAT_80119ed8 + (uint)param_1 * 4), *(int *)pbVar10 != -1)) &&
     (DAT_80119eab != -1)) {
    if ((*pbVar10 & 0x80) != 0) {
      uVar12 = *pbVar10 & 0x7f;
    }
    bVar1 = pbVar10[2];
    uVar11 = pbVar10[3] & 0x1f;
    cVar5 = FUN_800787dc(uVar11,bVar1 & 0xf);
    if (cVar5 == '\0') {
      bVar2 = pbVar10[1];
      bVar3 = pbVar10[2];
      bVar4 = pbVar10[3];
      (&DAT_80119efc)[uVar11 * 2] = bVar1 & 7;
      (&DAT_80119efd)[uVar11 * 2] = (char)uVar11;
      iVar6 = uVar11 * 0x24;
      (&DAT_80119f2c)[iVar6] = 1;
      (&DAT_80119f2d)[iVar6] = param_1;
      cVar5 = DAT_8011a28e;
      *(ushort *)(&DAT_80119f30 + iVar6) = uVar12;
      uVar7 = (ushort)(bVar3 >> 4);
      uVar8 = (uint)(bVar4 >> 5);
      *(ushort *)(&DAT_80119f32 + iVar6) = bVar2 & 0x7f;
      *(ushort *)(&DAT_80119f34 + iVar6) = (ushort)(bVar3 >> 4);
      *(float *)(&DAT_80119f40 + iVar6) = (float)(int)param_2[10];
      *(float *)(&DAT_80119f44 + iVar6) = (float)(int)param_2[0xb];
      *(float *)(&DAT_80119f48 + iVar6) = (float)(int)param_2[0xc];
      *(undefined2 *)(&DAT_80119f3e + iVar6) = 1;
      if (cVar5 == '\0') {
        *(undefined2 *)(&DAT_80119f4c + iVar6) = 0;
      }
      else {
        *(undefined2 *)(&DAT_80119f4c + iVar6) = 1;
      }
      if (uVar8 != 0) {
        pbVar10 = &DAT_80119efc + uVar11 * 2;
        puVar9 = &DAT_80119f2c + uVar11 * 0x24;
        do {
          uVar8 = uVar8 - 1;
          uVar11 = uVar11 + 1;
          pbVar10[2] = bVar1 & 7;
          pbVar10[3] = (byte)uVar11;
          uVar7 = uVar7 + 1;
          if (DAT_8011a28e == '\0') {
            *(undefined2 *)(puVar9 + 0x44) = 0;
          }
          else {
            *(undefined2 *)(puVar9 + 0x44) = 1;
          }
          puVar9[0x25] = param_1;
          puVar9[0x24] = 1;
          *(ushort *)(puVar9 + 0x28) = uVar12;
          *(ushort *)(puVar9 + 0x2a) = bVar2 & 0x7f;
          *(ushort *)(puVar9 + 0x2c) = uVar7;
          *(float *)(puVar9 + 0x38) = (float)(int)param_2[10];
          *(float *)(puVar9 + 0x3c) = (float)(int)param_2[0xb];
          *(float *)(puVar9 + 0x40) = (float)(int)param_2[0xc];
          *(undefined2 *)(puVar9 + 0x36) = 1;
          pbVar10 = pbVar10 + 2;
          puVar9 = puVar9 + 0x24;
        } while (uVar8 != 0);
      }
    }
  }
  return;
}
