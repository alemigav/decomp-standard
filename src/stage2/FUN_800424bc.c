/* FUN_800424bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800424bc  body 0x800424bc..0x800424eb  size 48 B
 * body sha256 c48828cf4e93ab6da92f8d5f1c0370ff6dc6fd4e8d5b18f17e0da3ac297bdfab
 * provider record sha256 43f34684f67589aec2fe49aaec875d04976fea8940051e8bcdd20212ac9a016e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_800424bc(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  return param_2;
}
