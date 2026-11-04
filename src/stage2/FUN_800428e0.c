/* FUN_800428e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800428e0  body 0x800428e0..0x80042a23  size 324 B
 * body sha256 b0a6fa67f6a04f72de4a69a50cf8fc82bb6f4ea308aef9aee4082ee1b83d48b0
 * provider record sha256 7c77106b1590cde3c69e468b26ddbf8bdd6974c17ec831971713d9ce1406057d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800428e0(int param_1)

{
  float fVar1;
  
  DAT_801315e8 = param_1 << 7;
  fVar1 = (float)DAT_801315e8;
  DAT_800efc50 = (undefined2)param_1;
  DAT_800efc54 = (fVar1 + 512.0) / (512.0 - fVar1);
  DAT_800efc52 = (undefined2)((param_1 * 0xf0) / 0xe0);
  DAT_800efc58 = (fVar1 * 1024.0) / (512.0 - fVar1);
  fVar1 = (float)param_1;
  FUN_80047d70(113.0 / fVar1,0x3f800000);
  DAT_80131708 = (float)DAT_801315e8 * 0.25;
  DAT_80131700 = fVar1 * 114.59155;
  DAT_8013170c = 0x3fb5aaab;
  DAT_80131704 = 0x43000000;
  func_0x80009470(&DAT_80131600,&DAT_80131710,DAT_80131700,0x3fb5aaab,0x43000000,DAT_80131708,
                  0x3f800000);
  return;
}
