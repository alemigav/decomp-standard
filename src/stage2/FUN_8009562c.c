/* FUN_8009562c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009562c  body 0x8009562c..0x80095b8f  size 100 B
 * body sha256 faa2bff100228399816e3eefd577c199183236969807eeab59e3d8789bdc89ec
 * provider record sha256 24e571ea1c79429f563e993923849a6da9686f01b95a7cd02a88cc16cacf6af5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009562c(void)

{
  byte *pbVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  byte bVar6;
  ushort uVar5;
  int iVar7;
  undefined4 uVar8;
  undefined *puVar9;
  uint uVar10;
  undefined2 *puVar11;
  
  puVar3 = DAT_800dfbe0;
  switch(DAT_8012bf9a) {
  case '\0':
    if (DAT_8012fe04 == '\0') {
      puVar4 = (ushort *)
               (&DAT_801302d0 +
               (uint)(byte)(&DAT_800e8ff4)[DAT_8012bfa9 * 8 + (int)(char)DAT_8012bfaa] * 4);
    }
    else {
      iVar7 = (int)((uint)DAT_8012bfaa << 0x18) >> 0x18;
      uVar10 = iVar7 - ((int)((uint)DAT_8012bfaa << 0x18) >> 0x1f) >> 1;
      if ((iVar7 + uVar10 * -2 & 0xff) == 0) {
        uVar10 = (uint)((byte)(&DAT_800e9013)[uVar10 & 0xff] >> 4);
      }
      else {
        uVar10 = (byte)(&DAT_800e9013)[uVar10 & 0xff] & 0xf;
      }
      puVar4 = (ushort *)(&DAT_80130334 + uVar10 * 4);
    }
    if (DAT_8012bfc1 == '\0') {
      if (0x50 < DAT_8012bfc0) {
        DAT_8012bfc1 = '\x01';
      }
      DAT_8012bfc0 = DAT_8012bfc0 + 2;
    }
    else {
      if (DAT_8012bfc0 < 10) {
        DAT_8012bfc1 = '\0';
      }
      DAT_8012bfc0 = DAT_8012bfc0 - 2;
    }
    if ((DAT_800df918 & 0x2000) == 0) {
      if ((-1 < DAT_800e10ec) || ((DAT_800df90c & 0xa000) == 0)) break;
      if ((DAT_800df90c & 0x2000) == 0) {
LAB_80095830:
        if (((DAT_800df90c & 0x8000) == 0) || (DAT_8012bfab == 0)) break;
        DAT_8012bf9a = '\x04';
        DAT_8012bfab = DAT_8012bfab - 1;
      }
      else {
        if (*puVar4 <= (ushort)DAT_8012bfab) {
          DAT_8012bf9a = '\x01';
          FUN_80077adc(0x4040000,0);
          goto LAB_80095830;
        }
        DAT_8012bf9a = '\x02';
        DAT_8012bfab = DAT_8012bfab + 1;
      }
      uVar8 = 0x4080000;
    }
    else {
      DAT_8012bf9a = '\x06';
      FUN_8004ac04(0xaf0010,0xe400,10,0);
      uVar8 = 0x4050000;
    }
LAB_800958e4:
    FUN_80077adc(uVar8,0);
    break;
  case '\x01':
    if ((DAT_800e10ec < 0) && ((DAT_800df90c & 0x8000) != 0)) {
      DAT_8012bf9a = '\0';
      DAT_8012bfc1 = '\0';
      DAT_8012bfc0 = 2;
    }
    if ((DAT_800df918 & 0x3000) != 0) {
      DAT_8012bf9a = '\x06';
      FUN_8004ac04(0xaf0010,0xe400,10,0);
      uVar8 = 0x4060000;
      goto LAB_800958e4;
    }
    break;
  case '\x02':
  case '\x03':
    bVar6 = DAT_8012bf9b + 1;
    if (DAT_8012bf9b < 0xb) {
      if (DAT_8012bf9a == '\x02') {
        bVar6 = (&DAT_8012fe48)[bVar6];
      }
      else {
        bVar6 = (&UNK_8012fe53)[-(uint)bVar6];
      }
      uVar5 = -(ushort)bVar6;
      goto LAB_80095a28;
    }
    if (DAT_8012bf9a == '\x02') {
      DAT_8012bf9b = bVar6;
      FUN_800946f0();
      DAT_8012bff4 = 0x138;
      DAT_8012bf9a = '\x03';
    }
    else {
      DAT_8012bf9a = '\0';
    }
LAB_800959c8:
    DAT_8012bf9b = 0;
    DAT_8012bfc1 = '\0';
    DAT_8012bfc0 = 2;
    break;
  case '\x04':
  case '\x05':
    bVar6 = DAT_8012bf9b + 1;
    if (10 < DAT_8012bf9b) {
      if (DAT_8012bf9a == '\x04') {
        DAT_8012bf9b = bVar6;
        FUN_800946f0();
        DAT_8012bff4 = -0x106;
        DAT_8012bf9a = '\x05';
      }
      else {
        DAT_8012bf9a = '\0';
      }
      goto LAB_800959c8;
    }
    if (DAT_8012bf9a == '\x04') {
      bVar6 = (&DAT_8012fe48)[bVar6];
    }
    else {
      bVar6 = (&UNK_8012fe53)[-(uint)bVar6];
    }
    uVar5 = (ushort)bVar6;
LAB_80095a28:
    DAT_8012bf9b = DAT_8012bf9b + 1;
    DAT_8012bff4 = DAT_8012bff4 + uVar5;
    break;
  case '\x06':
    if ((DAT_8010b294 & 0x80) == 0) {
      pbVar1 = DAT_800dfbe0 + 1;
      *DAT_800dfbe0 = 0;
      if ((*pbVar1 & 0x80) == 0) {
        puVar11 = (undefined2 *)(puVar3 + 0xc);
      }
      else {
        puVar11 = (undefined2 *)(puVar3 + 0x14);
      }
      DAT_800e8c7e = *puVar11;
      if (DAT_800e8ca8 < 4) {
        uVar2 = puVar11[2];
        puVar9 = &DAT_800e8d48;
      }
      else {
        uVar2 = puVar11[2];
        puVar9 = &DAT_800e8d68;
      }
      FUN_80083758(puVar9,uVar2);
      uVar10 = (uint)*(byte *)(puVar11 + 3);
      if (uVar10 < 0x20) {
        (&DAT_800e18f8)[uVar10 * 0xda] = 0;
      }
      if ((*(byte *)((int)puVar11 + 7) & 0x80) != 0) {
        FUN_80038e98(5,(*(byte *)((int)puVar11 + 7) & 0x60) >> 2 | 7,&DAT_800e190c + uVar10 * 0x368)
        ;
      }
      FUN_80077adc(0x4050000,0);
      DAT_8012bf99 = 0;
    }
    DAT_8012fe04 = '\0';
  default:
    goto LAB_80095b78;
  }
  FUN_80095280();
LAB_80095b78:
  return;
}
