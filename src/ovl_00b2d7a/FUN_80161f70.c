/* FUN_80161f70
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x80161f70  body 0x80161f70..0x80161feb  size 124 B
 * body sha256 6ade3a2569af0b7eff75a25e378a188621fff61073e488f8dbaa3e79d67e3f29
 * provider record sha256 dcaded3ed57c4989ecafc45e9ec5eefc77957ad8cf04d59f97a71a9a102a86eb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161f70(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_LAB_80162628)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_LAB_80162628)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
