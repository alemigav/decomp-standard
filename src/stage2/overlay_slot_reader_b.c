/* overlay_slot_reader_b
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cd08  body 0x8004cd08..0x8004cd53  size 76 B
 * body sha256 c4975c5534f85f9b5c5acdf0c8fff28172d3d196e9fba699b45200572e00368b
 * provider record sha256 01d6bbceb80f289cfe7bf041d98ec02c77e6cdd16ece8a4eb9e91feddff9d07c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void overlay_slot_reader_b(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = cart_record((&DAT_8010b2e0)[param_1 * 8]);
  overlay_inflate(uVar1);
  FUN_8004ce40(*(undefined4 *)(&DAT_8010b2e4 + param_1 * 8));
  return;
}
