/* FUN_80095280
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80095280  body 0x80095280..0x8009562b  size 940 B
 * body sha256 27149aec0d4a2a1e52f198582917dd87b12686fb3c68e1aed6df398d34705d87
 * provider record sha256 b6b56c6b5e816042d1805d0603d7b80e9f6369ab4d56827a07ca99973daf9fbc
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80095280(void)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  
  iVar11 = DAT_800c52dc;
  uVar12 = 0;
  if (DAT_8012fe04 == '\0') {
    puVar2 = (ushort *)
             (&DAT_801302d0 +
             (uint)(byte)(&DAT_800e8ff4)[DAT_8012bfa9 * 8 + (int)(char)DAT_8012bfaa] * 4);
  }
  else {
    iVar10 = (int)((uint)DAT_8012bfaa << 0x18) >> 0x18;
    uVar3 = iVar10 - ((int)((uint)DAT_8012bfaa << 0x18) >> 0x1f) >> 1;
    if ((iVar10 + uVar3 * -2 & 0xff) == 0) {
      uVar3 = (uint)((byte)(&DAT_800e9013)[uVar3 & 0xff] >> 4);
    }
    else {
      uVar3 = (byte)(&DAT_800e9013)[uVar3 & 0xff] & 0xf;
    }
    puVar2 = (ushort *)(&DAT_80130334 + uVar3 * 4);
  }
  uVar1 = *puVar2;
  puVar8 = (undefined4 *)&DAT_8013a3a0;
  sVar9 = DAT_8012bff6;
  do {
    pcVar4 = (char *)*puVar8;
    if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
      FUN_8004a7a0((int)DAT_8012bff4,sVar9,0,0x4000,pcVar4);
    }
    puVar8 = puVar8 + 1;
    uVar12 = uVar12 + 1;
    sVar9 = sVar9 + 0x11;
  } while (uVar12 < 0xf);
  FUN_800478b8(iVar11 + 0x3f928,100,0x3c);
  DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar11 + 0x3f928,0,0);
  iVar10 = iVar11 + 0x3f950;
  if (DAT_8012bfab == uVar1) {
    FUN_800479bc(iVar10,0x2a,0xe);
    FUN_800478ac(iVar10,0x38,0xc);
    FUN_800478b8(iVar10,0x118,0x6e);
    *(undefined2 *)(iVar11 + 0x3f95a) = 0;
    if ((DAT_8012bf9a == 1) || (DAT_8012bf9a == 0xe)) {
      uVar5 = 0x80;
      uVar6 = 0x80;
      uVar7 = 0x80;
    }
    else {
      uVar5 = 0x30;
      uVar6 = 0x30;
      uVar7 = 0x30;
    }
  }
  else {
    FUN_800479bc(iVar10,0xc,0xd);
    FUN_800478ac(iVar10,0x2a,0xc);
    FUN_800478b8(iVar10,(uint)DAT_8012bfc1 * 3 + 0x11a,0x6e);
    uVar5 = 0x80;
    uVar6 = 0x80;
    uVar7 = 0x80;
    *(undefined2 *)(iVar11 + 0x3f95a) = 0x40;
  }
  FUN_8004786c(iVar10,uVar5,uVar6,uVar7);
  if ((DAT_8012bf9a < 2) || (DAT_8012bf9a - 0xd < 2)) {
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar10,0,0);
  }
  iVar11 = iVar11 + 0x3f978;
  FUN_8004786c(iVar11,0x80,0x80,0x80);
  FUN_800478b8(iVar11,(ushort)DAT_8012bfc1 * -3 + 0xc,0x6e);
  if ((DAT_8012bf9a == 0) && (DAT_8012bfab != 0)) {
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar11,0,0);
  }
  if ((DAT_8012bf9a == 0xd) && (DAT_8012bfab != 0)) {
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar11,0,0);
  }
  return;
}
