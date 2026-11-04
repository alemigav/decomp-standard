/* thread2_entry
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800282e8  body 0x800282e8..0x80028307  size 32 B
 * body sha256 ff8665dc402fd3c8a2201ae69984ce8a4a9740890976b18bc87daea3ae7a7b5c
 * provider record sha256 902e87d4f3d57366f88aed4f9363271e129c8df38f91e606acd029b968efb78e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void thread2_entry(void)

{
  FUN_80026524();
  do {
    scene_load_caller();
  } while( true );
}
