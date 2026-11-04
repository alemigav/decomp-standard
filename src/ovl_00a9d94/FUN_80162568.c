/* FUN_80162568
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80162568  body 0x80162568..0x801625e3  size 124 B
 * body sha256 4ad7f2f2fcefcee0d212f245ff7cd87b6d4f2eb54a8967fd1cd4300217796935
 * provider record sha256 2d6b924ed5dae17d42ee0c7d7dfb1737a9f313cceb13b8b81f6ccfb3f5583b4f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162568(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8016c408)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8016c450)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
