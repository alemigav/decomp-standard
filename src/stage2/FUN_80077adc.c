/* FUN_80077adc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80077adc  body 0x80077adc..0x80077d17  size 572 B
 * body sha256 e9eb5e2915117faf0a141621f3661c4253ef90c268c8f46d390c7de6c3118980
 * provider record sha256 c6c0fe6748281d34313b0f8f965501dee2cf483566198c40e065903992370900
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80077adc(uint param_1,int *param_2)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  undefined *puVar8;
  uint uVar9;
  uint uVar10;
  ushort uVar11;
  undefined1 uVar12;
  ushort uVar13;
  
  uVar5 = param_1 >> 0x18;
  if ((&DAT_80119ea8)[uVar5] != -1) {
    pbVar7 = (byte *)((&DAT_80119ecc)[uVar5] + (param_1 >> 0x10 & 0xff) * 4);
    uVar13 = (ushort)param_1 & 0xff;
    if (*(int *)pbVar7 != -1) {
      if ((*pbVar7 & 0x80) != 0) {
        uVar5 = *pbVar7 & 0x7f;
      }
      bVar2 = pbVar7[2];
      bVar3 = pbVar7[1];
      uVar9 = pbVar7[3] & 0x1f;
      uVar11 = (ushort)(bVar2 >> 4);
      uVar10 = (uint)(pbVar7[3] >> 5);
      cVar4 = FUN_800787dc(uVar9,bVar2 & 0xf);
      if (cVar4 == '\0') {
        (&DAT_80119efc)[uVar9 * 2] = bVar2 & 7;
        (&DAT_80119efd)[uVar9 * 2] = (char)uVar9;
        iVar6 = uVar9 * 0x24;
        uVar12 = (undefined1)(param_1 >> 0x10);
        (&DAT_80119f2d)[iVar6] = uVar12;
        (&DAT_80119f2c)[iVar6] = 1;
        *(short *)(&DAT_80119f30 + iVar6) = (short)uVar5;
        *(ushort *)(&DAT_80119f32 + iVar6) = bVar3 & 0x7f;
        *(ushort *)(&DAT_80119f34 + iVar6) = (ushort)(bVar2 >> 4);
        if (param_2 != (int *)0x0) {
          *(float *)(&DAT_80119f40 + iVar6) = (float)*param_2;
          *(float *)(&DAT_80119f44 + iVar6) = (float)param_2[1];
          *(float *)(&DAT_80119f48 + iVar6) = (float)param_2[2];
        }
        bVar1 = DAT_8011a28e == '\0';
        *(ushort *)(&DAT_80119f3e + iVar6) = uVar13;
        if (bVar1) {
          *(undefined2 *)(&DAT_80119f4c + iVar6) = 0;
        }
        else {
          *(undefined2 *)(&DAT_80119f4c + iVar6) = 1;
        }
        if (uVar10 != 0) {
          pbVar7 = &DAT_80119efc + uVar9 * 2;
          puVar8 = &DAT_80119f2c + uVar9 * 0x24;
          do {
            uVar10 = uVar10 - 1;
            uVar9 = uVar9 + 1;
            pbVar7[2] = bVar2 & 7;
            pbVar7[3] = (byte)uVar9;
            puVar8[0x25] = uVar12;
            puVar8[0x24] = 1;
            cVar4 = DAT_8011a28e;
            uVar11 = uVar11 + 1;
            *(short *)(puVar8 + 0x28) = (short)uVar5;
            *(ushort *)(puVar8 + 0x2a) = bVar3 & 0x7f;
            *(ushort *)(puVar8 + 0x2c) = uVar11;
            if (cVar4 == '\0') {
              *(undefined2 *)(puVar8 + 0x44) = 0;
            }
            else {
              *(undefined2 *)(puVar8 + 0x44) = 1;
            }
            if (param_2 != (int *)0x0) {
              *(float *)(puVar8 + 0x38) = (float)*param_2;
              *(float *)(puVar8 + 0x3c) = (float)param_2[1];
              *(float *)(puVar8 + 0x40) = (float)param_2[2];
            }
            *(ushort *)(puVar8 + 0x36) = uVar13;
            pbVar7 = pbVar7 + 2;
            puVar8 = puVar8 + 0x24;
          } while (uVar10 != 0);
        }
      }
    }
  }
  return;
}
