/* FUN_8002584c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002584c  body 0x8002584c..0x800258d7  size 140 B
 * body sha256 ffd3fc6351de5c5035442235826501529a20d58c7b1f6faf71c0c1c8b4181828
 * provider record sha256 b1faa680417ec2373c617809cbff79cfc27ee0c4e5f2ef9683ff855ef2a633c7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002584c(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  DAT_800c763c = param_1;
  *param_1 = 1;
  param_1[3] = 0xd0;
  param_1[5] = 0x1000;
  param_1[7] = 0x800;
  param_1[4] = &DAT_8001b740;
  param_1[2] = entry;
  param_1[6] = &DAT_800bb680;
  uVar2 = DAT_800c56e4;
  uVar1 = DAT_800c4ea0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xc] = &DAT_800c69b8;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[10] = uVar1;
  param_1[0xb] = uVar2;
  return;
}
