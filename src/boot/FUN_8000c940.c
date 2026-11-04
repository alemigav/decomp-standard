/* FUN_8000c940
 * image   boot (boot), base 0x80000480
 * address 0x8000c940  body 0x8000c940..0x8000c9d3  size 148 B
 * body sha256 9925492d7dddcf38503cf1079a9c4936a977118d3ff6e1defc8e0bc0b78cffb5
 * provider record sha256 fc6477f66337ce70e4c303ca94dc37481dae2f406bd2a2fe9a972898f941d372
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8000c940(uint param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    FUN_8000c620(0x80011bb0,0x80011bb4,0x3d);
  }
  do {
  } while ((_DAT_a4600010 & 3) != 0);
  *param_2 = *(undefined4 *)(_DAT_80000308 | param_1 | 0xa0000000);
  return 0;
}
