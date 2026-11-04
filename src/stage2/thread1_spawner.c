/* thread1_spawner
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006cb94  body 0x8006cb94..0x8006cc4f  size 188 B
 * body sha256 0347fb8b30c4ee1d3fbe3dda4d94701f0a994e40733680601db7b4b4407bd53a
 * provider record sha256 7cd3373a8dd669a842b7899891f186dc2b832b88c602f6eb6bb758dd49e909e6
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void thread1_spawner(void)

{
  func_0x8000e4c0(0xfe);
  osCreateMesgQueue(0x80139f10,0x80139ff0,0x14);
  osSetEventMesg(4,0x80139f10,1);
  osSetEventMesg(9,0x80139f10,2);
  osSetEventMesg(6,0x80139f10,10);
  osSetEventMesg(0xe,0x80139f10,8);
  osCreateThread(&DAT_80112a40,1,thread1_entry,0,&DAT_800bdca0,0x28);
  osStartThread(&DAT_80112a40);
  return;
}
