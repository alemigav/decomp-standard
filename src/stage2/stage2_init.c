/* stage2_init
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d190  body 0x8004d190..0x8004d31f  size 400 B
 * body sha256 9d9121ea944dbf29d59448a05d68e9bc5a8d518f02105d1fa227c19d77d03ac9
 * provider record sha256 e8b24c84f9002b95570d857c93ca55dd62e9cf3539e36111da215957245265d2
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void stage2_init(void)

{
  if (_DAT_80000318 < 0x400001) {
    DAT_801137f0 = 0x140;
    DAT_801137f4 = 0xf0;
    DAT_8010b6e0 = 0x803da800;
    DAT_8010b6f8 = 0x803b5000;
    DAT_8010b6e4 = 0x8038f800;
    DAT_8010b6f0 = 0x8038f800;
    DAT_8010b6ec = 0;
    DAT_8010b6e8 = 0x801af200;
    DAT_8010b6f4 = 0x801d4a00;
  }
  else {
    DAT_801137f0 = 0x280;
    DAT_801137f4 = 0x1e0;
    DAT_8010b6e0 = 0x8076a000;
    DAT_8010b6f8 = 0x806d4000;
    DAT_8010b6e4 = 0x8063e000;
    DAT_8010b6f0 = 0x8063e000;
    DAT_8010b6e8 = 0x8021fa00;
    DAT_8010b6ec = 0x802b5a00;
    DAT_8010b6f4 = 0x8034ba00;
  }
  DAT_8010b6fc = 0x80189a00;
  framebuffer_set();
  thread9_spawner();
  thread1_spawner();
  idle_spin();
  return;
}
