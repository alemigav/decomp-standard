/* FUN_8008f0a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f0a8  body 0x8008f0a8..0x8008f117  size 112 B
 * body sha256 e090d08dda60f9039a6846b20bb165313a08b872bf21f44e4d64574a68db51c5
 * provider record sha256 d7083db2d32b64da7c6966c75d919d622c533416ac3bf7b2665f2f2099ed4498
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f0a8(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4];
  DAT_8012bfae = 0;
  switch(DAT_8012bf9c) {
  case '\0':
    FUN_800479c8(DAT_800c52dc + 0x44800,&DAT_8012fa38,*(undefined2 *)(&DAT_8012f5e0 + uVar1 * 2));
    DAT_800e1124 = 0x817;
    FUN_800824b0(DAT_800c52dc + 0x44800);
    FUN_80096e74(0);
    FUN_800986a4(0);
    DAT_8012bfe6 = 0x102;
    DAT_8012bf9d = 0;
    DAT_8012bf9c = DAT_8012bf9c + '\x01';
  case '\x01':
    DAT_8012bfd0 = DAT_8012bfd0 + -0xc;
  case '\x02':
    goto FUN_8008f19c;
  case '\x03':
    DAT_8012bf9d = DAT_8012bf9d + 1;
    if (6 < DAT_8012bf9d) {
      DAT_8012bf9d = 0;
      DAT_8012bf9c = DAT_8012bf9c + '\x01';
    }
    DAT_8012bfe6 = DAT_8012bfe6 + -0xf;
    break;
  case '\x04':
    DAT_8012bfe6 = DAT_8012bfe6 + -0xf;
    DAT_8012bfd0 = DAT_8012bfd0 + -0xc;
  case '\x05':
    DAT_8012bf9d = DAT_8012bf9d + 1;
    if (4 < DAT_8012bf9d) {
      DAT_8012bf9d = 0;
      DAT_8012bf9c = DAT_8012bf9c + '\x01';
    }
    DAT_8012bfd2 = DAT_8012bfd2 + -8;
LAB_8008f368:
    DAT_8012bfd0 = DAT_8012bfd0 + 6;
    break;
  case '\x06':
    DAT_8012bf9d = DAT_8012bf9d + 1;
    if (8 < DAT_8012bf9d) {
      FUN_8004ac04(0xaf0010,0xe400,uVar1 + 0x10,0);
      DAT_8012bf9c = DAT_8012bf9c + '\x01';
    }
    break;
  case '\a':
    if ((DAT_8010b294 & 0x80) != 0) break;
    FUN_80077adc(0x4050000,0,uVar1 + 0x10);
    FUN_80083758(&DAT_800e8d78,(&DAT_8012ffa9)[uVar1 * 8]);
    DAT_8012bf9c = '\b';
    goto LAB_8008f428;
  case '\b':
    DAT_8012bfd0 = DAT_8012bfd0 + -0xc;
  case '\t':
    DAT_8012bf9d = DAT_8012bf9d + 1;
    if (4 < DAT_8012bf9d) {
      DAT_8012bf9d = 0;
      DAT_8012bf9c = DAT_8012bf9c + '\x01';
    }
    DAT_8012bfd2 = DAT_8012bfd2 + 8;
    goto LAB_8008f368;
  case '\n':
    DAT_8012bf9d = DAT_8012bf9d + 1;
    if (6 < DAT_8012bf9d) {
      DAT_8012bf9d = 0;
      DAT_8012bf9c = DAT_8012bf9c + '\x01';
    }
    DAT_8012bfe6 = DAT_8012bfe6 + 0xf;
    break;
  case '\v':
    DAT_8012bfe6 = DAT_8012bfe6 + 0xf;
    DAT_8012bfd0 = DAT_8012bfd0 + -0xc;
  case '\f':
    DAT_8012bf9d = DAT_8012bf9d + 1;
    if (4 < DAT_8012bf9d) {
      DAT_8012bf9d = 0;
      DAT_8012bf9c = DAT_8012bf9c + '\x01';
    }
    DAT_8012bfd0 = DAT_8012bfd0 + 6;
    DAT_8012bfd8 = DAT_8012bfd8 + 6;
    DAT_8012bfd2 = DAT_8012bfd2 + -8;
    break;
  case '\r':
    DAT_8012bf9c = '\0';
    DAT_8012bf9b = 0;
    DAT_8012bf9a = 0;
LAB_8008f428:
    DAT_8012bf9d = 0;
  }
LAB_8008f42c:
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
FUN_8008f19c:
  DAT_8012bf9d = DAT_8012bf9d + 1;
  if (4 < DAT_8012bf9d) {
    DAT_8012bf9d = 0;
    DAT_8012bf9c = DAT_8012bf9c + '\x01';
  }
  DAT_8012bfd0 = DAT_8012bfd0 + 6;
  DAT_8012bfd2 = DAT_8012bfd2 + 8;
  DAT_8012bfe0 = DAT_8012bfe0 + 8;
  DAT_8012bfd8 = DAT_8012bfd8 + -6;
  goto LAB_8008f42c;
}
