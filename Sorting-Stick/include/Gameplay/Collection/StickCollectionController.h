#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>

namespace Gameplay
{
    namespace Collection
    {
        class StickCollectionView;
        class StickCollectionModel;
        struct Stick;
        enum class SortType;
        enum class SortState;

        class StickCollectionController
        {
        private:
            StickCollectionView* collection_view;
            StickCollectionModel* collection_model;

            std::vector<Stick*> sticks;
            SortType sort_type;
            SortState sortState;

            std::thread sort_thread;

            int number_of_comparisons;
            int number_of_array_access;
            int current_operation_delay;

            int colorDelay;

            int delay_in_ms;
            sf::String time_complexity;

            void initializeSticks();
            float calculateStickWidth();
            float calculateStickHeight(int array_pos);

            void updateStickPosition();
            void updateStickPosition(int i);
            void shuffleSticks();
            bool compareSticksByData(const Stick* a, const Stick* b) const;

            void resetSticksColor();
            void resetVariables();

            void processSortThreadState();

            bool isCollectionSorted();
            void destroy();

            void ProcessBubbleSort();
            
            void ProcessInsertionSort();

            void ProcessSelectionSort();

            void ProcessMergeSort();
            void Merge(int left, int mid, int right);
            void MergeSort(int left, int right);

            void InPlaceMerge(int left, int mid, int right);
            void InPlaceMergeSort(int left, int right);

            void ProcessQuickSort();
            int Partition(int left, int right);
            void QuickSort(int left, int right);

            void ProcessRadixSort();
            void CountSort(int exponent);
            void RadixSort();

            void SetCompletedColor();

        public:
            StickCollectionController();
            ~StickCollectionController();

            void initialize();
            void update();
            void render();

            void reset();
            void sortElements(SortType sort_type);

            SortType getSortType();
            int getNumberOfComparisons();
            int getNumberOfArrayAccess();

            int getNumberOfSticks();
            int getDelayMilliseconds();
            sf::String getTimeComplexity();
        };
    }
}